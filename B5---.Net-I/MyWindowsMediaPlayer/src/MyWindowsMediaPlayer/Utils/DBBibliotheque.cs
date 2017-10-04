using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Data;
using System.Data.SQLite;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using MahApps.Metro.Controls;
using MahApps.Metro.Controls.Dialogs;
using TagLib.Matroska;
using Application = System.Windows.Application;
using File = System.IO.File;
using MyWindowsMediaPlayer.Model;
using System.Text.RegularExpressions;


namespace MyWindowsMediaPlayer
{
    class DBBibliotheque
    {
        #region " Instance + DataBase Variables "
        private static DBBibliotheque instance;
        private SQLiteConnection m_dbConnection;
        #endregion

        #region " Table DataBase + DataBase Name "
        private const string DB_NAME = "bibliotheque.sqlite";
        private const string DB_MUSIQUE = "musique";
        private const string DB_VIDEO = "video";
        private const string DB_IMAGE = "image";
        private const string DB_ARTISTE = "artiste";
        private const string DB_ALBUM_MUSIQUE = "album_musique";
        private const string DB_ALBUM_IMAGE = "album_image";
        private const string DB_PLAYLIST = "playlist";
        private const string DB_PLAYLIST_SONGS = "playlist_songs";
        #endregion

        #region " Query in DB "
        #region "CREATE queries"
        private const string CREATE_TABLE_VIDEO = "CREATE TABLE IF NOT EXISTS " + DB_VIDEO + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT," + "duration TEXT, path TEXT UNIQUE)";
        private const string CREATE_TABLE_IMAGE = "CREATE TABLE IF NOT EXISTS " + DB_IMAGE + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT," + "id_album INTEGER, path TEXT UNIQUE)";
        private const string CREATE_TABLE_MUSIC = "CREATE TABLE IF NOT EXISTS " + DB_MUSIQUE + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, " + "duration TEXT, id_artiste INTEGER, id_album INTEGER, path TEXT UNIQUE, " + "FOREIGN KEY(id_artiste) REFERENCES artiste(id), " + "FOREIGN KEY(id_album) REFERENCES album_musique(id))";
        private const string CREATE_TABLE_PLAYLIST = "CREATE TABLE IF NOT EXISTS " + DB_PLAYLIST + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT UNIQUE NOT NULL)";
        private const string CREATE_TABLE_PLAYLIST_SONGS = "CREATE TABLE IF NOT EXISTS " + DB_PLAYLIST_SONGS + " (id INTEGER PRIMARY KEY AUTOINCREMENT, id_playlist INTEGER, id_music INTEGER, FOREIGN KEY(id_playlist) REFERENCES " + DB_PLAYLIST + "(id), FOREIGN KEY(id_music) REFERENCES " + DB_MUSIQUE + "(id));";
        private const string CREATE_TABLE_ARTIST = "CREATE TABLE IF NOT EXISTS " + DB_ARTISTE + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT UNIQUE)";
        private const string CREATE_TABLE_ALBUM_IMAGE = "CREATE TABLE IF NOT EXISTS " + DB_ALBUM_IMAGE + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT)";
        private const string CREATE_TABLE_ALBUM_MUSIC = "CREATE TABLE IF NOT EXISTS " + DB_ALBUM_MUSIQUE + " (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT UNIQUE, id_artiste INTEGER)";
        #endregion
        #region "SELECT queries"
        private const string SELECT_ALL_FROM_DB_MUSIC = "SELECT * FROM " + DB_MUSIQUE + ";";
        private const string SELECT_ALL_FROM_DB_VIDEO = "SELECT * FROM " + DB_VIDEO + ";";
        private const string SELECT_ALL_FROM_DB_IMAGE = "SELECT * FROM " + DB_IMAGE + ";";
        private const string SELECT_ALL_FROM_DB_PLAYLIST = "SELECT * FROM " + DB_PLAYLIST + ";";
        private const string SELECT_IMG_ALB_FROM_DB_IMAGE = "SELECT img.name, img.path, album.name, img.id FROM " + DB_IMAGE + " AS img, " + DB_ALBUM_IMAGE + " AS album WHERE img.id_album = album.id;";
        private const string SELECT_MUS_ALB_ART_FROM_DB_MUSIC = "SELECT music.name, music.duration, music.path, artist.name, album.name, music.id FROM " + DB_MUSIQUE + " AS music, " + DB_ARTISTE + " AS artist, " + DB_ALBUM_MUSIQUE + " AS album WHERE music.id_artiste = artist.id AND music.id_album = album.id;";
        private const string SELECT_MUS_ALB_ART_FROM_DB_MUSIC_WITH_ID = "SELECT music.name, music.duration, music.path, artist.name, album.name FROM " + DB_MUSIQUE + " AS music, " + DB_ARTISTE + " AS artist, " + DB_ALBUM_MUSIQUE + " AS album WHERE music.id_artiste = artist.id AND music.id_album = album.id AND music.id = @id;";
        private const string SELECT_ID_FROM_DB_VIDEO = "SELECT id FROM " + DB_VIDEO + " WHERE path = @path;";
        private const string SELECT_ID_FROM_DB_VIDEO_WITH_ID = "SELECT id FROM " + DB_VIDEO + " WHERE id = @id;";
        private const string SELECT_ID_FROM_DB_IMAGE = "SELECT id FROM " + DB_IMAGE + " WHERE path = @path;";
        private const string SELECT_ID_FROM_DB_IMAGE_WITH_ID = "SELECT id FROM " + DB_IMAGE + " WHERE id = @id;";
        private const string SELECT_ID_FROM_DB_MUSIC = "SELECT id FROM " + DB_MUSIQUE + " WHERE path=@path;";
        private const string SELECT_MUS_FROM_DB_PLAYLIST = "SELECT musique.id, musique.name, musique.duration, musique.path, album_musique.name, artiste.name FROM musique JOIN playlist_songs ON musique.id = playlist_songs.id_music JOIN playlist ON playlist.id = playlist_songs.id_playlist JOIN album_musique ON album_musique.id = musique.id_album JOIN artiste ON artiste.id = musique.id_artiste WHERE playlist.id = @playlist;";
        private const string SELECT_ID_FROM_DB_MUSIC_WITH_ID = "SELECT id FROM " + DB_MUSIQUE + " WHERE id = @id;";
        private const string SELECT_ID_FROM_DB_ARTIST = "SELECT id FROM " + DB_ARTISTE + " WHERE name=@artist;";
        private const string SELECT_ID_FROM_DB_ARTIST_WITH_ID = "SELECT id FROM " + DB_ARTISTE + " WHERE id = @id;";
        private const string SELECT_ID_FROM_DB_ALBUM_MUSIC = "SELECT id FROM " + DB_ALBUM_MUSIQUE + " WHERE name=@album;";
        private const string SELECT_ID_FROM_DB_ALBUM_MUSIC_WITH_ID = "SELECT id FROM " + DB_ALBUM_MUSIQUE + " WHERE id = @id;";
        private const string SELECT_ID_FROM_DB_ALBUM_IMAGE = "SELECT id FROM " + DB_ALBUM_IMAGE + " WHERE name=@album;";
        private const string SELECT_ID_FROM_DB_ALBUM_IMAGE_WITH_ID = "SELECT id FROM " + DB_ALBUM_IMAGE + " WHERE id = @id;";
        private const string SELECT_LAST_ROW = " SELECT last_insert_rowid();";
        //Filters / search
        private const string SELECT_MUS_FROM_DB_MUSIC_SEARCH_MUS = "SELECT music.name, music.duration, music.path, artist.name, album.name, music.id FROM " + DB_MUSIQUE + " AS music, " + DB_ARTISTE + " AS artist, " + DB_ALBUM_MUSIQUE + " AS album WHERE music.id_artiste = artist.id AND music.id_album = album.id AND music.name LIKE @search;";
        private const string SELECT_VID_FROM_DB_VIDEO_SEARCH_VID = "SELECT * FROM " + DB_VIDEO + " WHERE name LIKE @search;";
        private const string SELECT_IMG_FROM_DB_IMAGE_SEARCH_IMG = "SELECT img.name, img.path, album.name, img.id FROM " + DB_IMAGE + " AS img, " + DB_ALBUM_IMAGE + " AS album WHERE img.id_album = album.id AND img.name LIKE @search;";
        private const string SELECT_MUS_FROM_DB_MUSIC_FILTER_ALB_OR_ALB = "SELECT music.name, music.path FROM " + DB_MUSIQUE + " AS music, " + DB_ARTISTE + " AS artist, " + DB_ALBUM_MUSIQUE + " AS album WHERE music.id_artiste = artist.id AND music.id_album = album.id AND (artist.name LIKE @filter OR album.name LIKE @filter);";
        private const string SELECT_IMG_FROM_DB_IMAGE_FILTER_ALB = "SELECT img.name FROM " + DB_IMAGE + " AS img, " + DB_ALBUM_IMAGE + " AS album WHERE img.id_album = album.id AND album.name LIKE @filter;";
        private const string SELECT_MUS_FROM_DB_MUSIC_SEARCH = "SELECT music.name, music.path FROM " + DB_MUSIQUE + " AS music, " + DB_ARTISTE + " AS artist, " + DB_ALBUM_MUSIQUE + " AS album WHERE music.id_artiste = artist.id AND music.id_album = album.id AND ((@music = 1 AND music.name LIKE @search) OR (@album = 1 AND album.name LIKE @search) OR (@artist = 1 AND artist.name LIKE @search));";
        private const string SELECT_IMG_FROM_DB_IMAGE_SEARCH = "SELECT img.name, img.path FROM " + DB_IMAGE + " AS img, " + DB_ALBUM_IMAGE + " AS album WHERE img.id_album = album.id AND ((@image = 1 AND img.name LIKE @search) OR (@album = 1 AND album.name LIKE @search));";
        private const string SELECT_VID_FROM_DB_VIDEO_SEARCH = "SELECT * FROM " + DB_VIDEO + " WHERE @video = 1 AND name LIKE @search;";
        #endregion
        #region "INSERT queries"
        private const string INSERT_DB_VIDEO = "INSERT INTO " + DB_VIDEO + " (name, duration, path) VALUES (@name, @duration, @path);";
        private const string INSERT_DB_IMAGE = "INSERT INTO " + DB_IMAGE + " (name, id_album, path) VALUES (@name, @album, @path);";
        private const string INSERT_DB_MUSIC = "INSERT INTO " + DB_MUSIQUE + " (name, duration, id_artiste, id_album, path) VALUES (@name, @duration, @idArtist, @idAlbum, @path);";
        private const string INSERT_DB_ARTIST = "INSERT INTO " + DB_ARTISTE + " (name) VALUES (@name);";
        private const string INSERT_DB_ALBUM_MUSIC = "INSERT INTO " + DB_ALBUM_MUSIQUE + " (name, id_artiste) VALUES (@name, @idArtist);";
        private const string INSERT_DB_ALBUM_IMAGE = "INSERT INTO " + DB_ALBUM_IMAGE + " (name) VALUES (@name);";
        private const string INSERT_DB_PLAYLIST = "INSERT INTO " + DB_PLAYLIST + " (name) VALUES (@name);";
        private const string INSERT_DB_PLAYLIST_SONG = "INSERT INTO " + DB_PLAYLIST_SONGS + " (id_playlist, id_music) VALUES(@id_playlist, @id_music);";
        #endregion
        #endregion

        #region " Constructor + Instance "
        public static DBBibliotheque Instance
        {
            get
            {
                if (instance == null)
                {
                    instance = new DBBibliotheque();
                }
                return instance;
            }
        }

        public DBBibliotheque()
        {
            this.init();
        }
        #endregion

        #region " Initialisation "
        private bool init()
        {
            if (this.createDataBase() && this.createTables())
            {
                this.addAlbumMusique("Unknown", "Unknown");
                return true;
            }
            return false;
        }

        private bool createDataBase()
        {
            if (File.Exists(DB_NAME))
            {
                if (connect())
                    return true;
            }
            else
            {
                try
                {
                    SQLiteConnection.CreateFile(DB_NAME);
                    if (File.Exists(DB_NAME))
                        if (connect())
                            return true;
                }
                catch (System.UnauthorizedAccessException e)
                {
                    throw e;
                }
            }
            return false;
        }

        /// <summary>
        /// It will create each tables if they don't exist.
        /// Useful to do it at the begining to optimize a little bit
        /// </summary>
        /// <returns>True if we created them and false if any problem</returns>
        private bool createTables()
        {
            try
            {
                SQLiteCommand command = new SQLiteCommand(CREATE_TABLE_VIDEO, this.m_dbConnection);
                command.ExecuteNonQuery();

                command = new SQLiteCommand(CREATE_TABLE_IMAGE, this.m_dbConnection);
                command.ExecuteNonQuery();

                command = new SQLiteCommand(CREATE_TABLE_MUSIC, this.m_dbConnection);
                command.ExecuteNonQuery();

                command = new SQLiteCommand(CREATE_TABLE_PLAYLIST, this.m_dbConnection);
                command.ExecuteNonQuery();

                command = new SQLiteCommand(CREATE_TABLE_ARTIST, this.m_dbConnection);
                command.ExecuteNonQuery();

                command = new SQLiteCommand(CREATE_TABLE_ALBUM_IMAGE, this.m_dbConnection);
                command.ExecuteNonQuery();

                command = new SQLiteCommand(CREATE_TABLE_ALBUM_MUSIC, this.m_dbConnection);
                command.ExecuteNonQuery();

                command = new SQLiteCommand(CREATE_TABLE_PLAYLIST_SONGS, this.m_dbConnection);
                command.ExecuteNonQuery();

                return true;
            }
            catch (UnauthorizedAccessException)
            {
                return false;
            }
        }

        private bool connect()
        {
            this.m_dbConnection = new SQLiteConnection("Data Source=" + DB_NAME + ";foreign keys=true;Version=3;");
            this.m_dbConnection.Open();
            if (this.m_dbConnection != null && this.m_dbConnection.State == ConnectionState.Closed)
                return false;
            return true;
        }
        #endregion

        private string formatString(string name)
        {
            return ("%" + Regex.Replace(Regex.Replace(name, "%", @"\%"), "_", @"\_") + "%");
        }

        #region " Send Information "
        public ObservableCollection<Filter> getSearchItems(string search, CheckFilter checkFilter)
        {
            ObservableCollection<Filter> items = new ObservableCollection<Filter>();
            search = this.formatString(search);
            try
            {
                SQLiteCommand command = new SQLiteCommand(SELECT_IMG_FROM_DB_IMAGE_SEARCH, this.m_dbConnection);
                command.Parameters.AddWithValue("@search", search);
                command.Parameters.AddWithValue("@image", checkFilter.Name);
                command.Parameters.AddWithValue("@album", checkFilter.Album);
                SQLiteDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    items.Add(new Filter()
                    {
                        Format = ViewModel.MainViewModel.FormatMedia.Image,
                        Name = reader[0].ToString(),
                        Path = reader[1].ToString()
                    });
                }
                command = new SQLiteCommand(SELECT_VID_FROM_DB_VIDEO_SEARCH, this.m_dbConnection);
                command.Parameters.AddWithValue("@search", search);
                command.Parameters.AddWithValue("@video", checkFilter.Name);
                reader = command.ExecuteReader();
                while (reader.Read())
                {
                    items.Add(new Filter()
                    {
                        Format = ViewModel.MainViewModel.FormatMedia.Video,
                        Name = reader["name"].ToString(),
                        Path = reader["path"].ToString()
                    });
                }
                command = new SQLiteCommand(SELECT_MUS_FROM_DB_MUSIC_SEARCH, this.m_dbConnection);
                command.Parameters.AddWithValue("@search", search);
                command.Parameters.AddWithValue("@music", checkFilter.Name);
                command.Parameters.AddWithValue("@album", checkFilter.Album);
                command.Parameters.AddWithValue("@artist", checkFilter.Artist);
                reader = command.ExecuteReader();
                while (reader.Read())
                {
                    items.Add(new Filter()
                    {
                        Format = ViewModel.MainViewModel.FormatMedia.Musique,
                        Name = reader[0].ToString(),
                        Path = reader[1].ToString()
                    });
                }
                return items;
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return items;
            }
        }

        public ObservableCollection<Filter> getNamesFiltered(string filter)
        {
            ObservableCollection<Filter> items = new ObservableCollection<Filter>();
            try
            {
                SQLiteCommand command = new SQLiteCommand(SELECT_MUS_FROM_DB_MUSIC_FILTER_ALB_OR_ALB, this.m_dbConnection);
                command.Parameters.AddWithValue("@filter", this.formatString(filter));
                SQLiteDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    items.Add(new Filter()
                    {
                        Format = ViewModel.MainViewModel.FormatMedia.Musique,
                        Name = reader[0].ToString(),
                        Path = reader[1].ToString()
                    });
                }
                command = new SQLiteCommand(SELECT_IMG_FROM_DB_IMAGE_FILTER_ALB, this.m_dbConnection);
                command.Parameters.AddWithValue("@filter", this.formatString(filter));
                reader = command.ExecuteReader();
                while (reader.Read())
                {
                    items.Add(new Filter()
                    {
                        Format = ViewModel.MainViewModel.FormatMedia.Image,
                        Name = reader[0].ToString(),
                        Path = reader[1].ToString()
                    });
                }
                return items;
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return items;
            }           
        }
        public ObservableCollection<MusicDB> GetListMusique()
        {
            try
            {
                ObservableCollection<MusicDB> item = new ObservableCollection<MusicDB>();
                SQLiteCommand command = new SQLiteCommand(SELECT_MUS_ALB_ART_FROM_DB_MUSIC, this.m_dbConnection);
                SQLiteDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    item.Add(new MusicDB()
                    {
                        ID = reader[5].ToString(),
                        Album = reader[4].ToString(),
                        Artiste = reader[3].ToString(),
                        Duration = reader[1].ToString(),
                        Path = reader[2].ToString(),
                        NameMusique = reader[0].ToString()
                    });
                }
                return item;
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return null;
            }
        }

        public ObservableCollection<PlaylistDB> GetListPlaylists()
        {
            ObservableCollection<PlaylistDB> item = new ObservableCollection<PlaylistDB>();
            try
            {
                SQLiteCommand command = new SQLiteCommand(SELECT_ALL_FROM_DB_PLAYLIST, this.m_dbConnection);
                SQLiteDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    ObservableCollection<MusicDB> musicsList = this.getListMusicFromPlaylist(reader["id"].ToString());
                    if (musicsList != null) {
                        item.Add(new PlaylistDB()
                        {
                            ID = Int32.Parse(reader["id"].ToString()),
                            NamePlaylist = reader["name"].ToString(),
                            MusicsList = musicsList
                        });
                    }
                }
                return item;
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return item;
            }
        }

        private ObservableCollection<MusicDB> getListMusicFromPlaylist(string id_playlist)
        {
            ObservableCollection<MusicDB> item = new ObservableCollection<MusicDB>();
            try
            {
                SQLiteCommand command = new SQLiteCommand(SELECT_MUS_FROM_DB_PLAYLIST, this.m_dbConnection);
                command.Parameters.AddWithValue("@playlist", id_playlist);
                SQLiteDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    Console.WriteLine("ADD MUSIQUE NP");
                    item.Add(new MusicDB()
                    {
                        ID = reader[0].ToString(),
                        NameMusique = reader[1].ToString(),
                        Duration = reader[2].ToString(),
                        Path = reader[3].ToString(),
                        Album = reader[4].ToString(),
                        Artiste = reader[5].ToString()
                    });
                }
                return item;
            }
            catch (Exception e)
            {
                Console.Error.WriteLine("ERROR MUSIC PLAYLIST");
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return item;
            }
        }

        public ObservableCollection<VideoDB> GetListVideo()
        {
            ObservableCollection<VideoDB> item = new ObservableCollection<VideoDB>();
            try
            {

                SQLiteCommand command = new SQLiteCommand(SELECT_ALL_FROM_DB_VIDEO, this.m_dbConnection);
                SQLiteDataReader reader = command.ExecuteReader();
                while (reader.Read())
                {
                    item.Add(new VideoDB()
                    {
                        ID = Int32.Parse(reader["id"].ToString()),
                        Duration = reader["duration"].ToString(),
                        Path = reader["path"].ToString(),
                        NameVideo = reader["name"].ToString()
                    });
                }
                return item;
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return item;
            }
        }

        public ObservableCollection<ImageDB> GetListImage()
        {
            ObservableCollection<ImageDB> item = new ObservableCollection<ImageDB>();
            try
            {
                if (createDataBase() && this.isTableExist(DB_IMAGE))
                {
                    SQLiteCommand command = new SQLiteCommand(SELECT_IMG_ALB_FROM_DB_IMAGE, this.m_dbConnection);
                    SQLiteDataReader reader = command.ExecuteReader();
                    while (reader.Read())
                    {
                        item.Add(new ImageDB()
                        {
                            ID = reader[3].ToString(),
                            Album = reader[2].ToString(),
                            Path = reader[1].ToString(),
                            NameImage = reader[0].ToString()
                        });
                    }
                }
                return item;
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return item;
            }
        }
        #endregion

        #region " Add M/V/I/P Region "
        public void addVideo(VideoDB video, ObservableCollection<VideoDB> itemSourceListVideo)
        {
            try
            {
                SQLiteCommand command;
                command = new SQLiteCommand(SELECT_ID_FROM_DB_VIDEO, this.m_dbConnection);
                command.Parameters.AddWithValue("@path", video.Path);
                SQLiteDataReader reader = command.ExecuteReader();
                if (!reader.Read())
                {
                    command = new SQLiteCommand(INSERT_DB_VIDEO + SELECT_LAST_ROW, this.m_dbConnection);
                    command.Parameters.AddWithValue("@name", video.NameVideo);
                    command.Parameters.AddWithValue("@duration", this.formatDuration(video.Duration));
                    command.Parameters.AddWithValue("@path", video.Path);
                    object result = command.ExecuteScalar();
                    if (result != null)
                    {
                        itemSourceListVideo.Add(new VideoDB()
                        {
                            ID = Int32.Parse(result.ToString()),
                            NameVideo = video.NameVideo,
                            Duration = this.formatDuration(video.Duration),
                            Path = video.Path
                        });
                    }
                }
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
            }
        }

        public void addImage(ImageDB image, ObservableCollection<ImageDB> itemSourceListImage)
        {
            try
            {
                string tmpAlbum = this.addAlbumImage(image.Album);
                if (tmpAlbum != null)
                {
                    SQLiteCommand command = new SQLiteCommand(SELECT_ID_FROM_DB_IMAGE, this.m_dbConnection);
                    command.Parameters.AddWithValue("@path", image.Path);
                    SQLiteDataReader reader = command.ExecuteReader();
                    if (!reader.Read())
                    {
                        command = new SQLiteCommand(INSERT_DB_IMAGE + SELECT_LAST_ROW, this.m_dbConnection);
                        command.Parameters.AddWithValue("@name", image.NameImage);
                        command.Parameters.AddWithValue("@album", tmpAlbum);
                        command.Parameters.AddWithValue("@path", image.Path);
                        object result = command.ExecuteScalar();
                        if (result != null)
                        {
                            itemSourceListImage.Add(new ImageDB()
                            {
                                ID = result.ToString(),
                                NameImage = image.NameImage,
                                Album = image.Album,
                                Path = image.Path
                            });
                        }
                    }
                }
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
            }
        }

        public void addMusique(MusicDB music, ObservableCollection<MusicDB> ItemsSource)
        {
            try
            {
                string tmpArtiste = this.addArtiste(music.Artiste);
                string tmpAlbum = this.addAlbumMusique(music.Album, tmpArtiste);
                if (tmpAlbum != null && tmpArtiste != null)
                {
                    SQLiteCommand command;
                    command = new SQLiteCommand(SELECT_ID_FROM_DB_MUSIC, this.m_dbConnection);
                    command.Parameters.AddWithValue("@path", music.Path);
                    SQLiteDataReader reader = command.ExecuteReader();
                    if (!reader.Read())
                    {
                        command = new SQLiteCommand(INSERT_DB_MUSIC + SELECT_LAST_ROW, this.m_dbConnection);
                        command.Parameters.AddWithValue("@name", music.NameMusique);
                        command.Parameters.AddWithValue("@duration", this.formatDuration(music.Duration));
                        command.Parameters.AddWithValue("@idArtist", tmpArtiste);
                        command.Parameters.AddWithValue("@idAlbum", tmpAlbum);
                        command.Parameters.AddWithValue("@path", music.Path);
                        object result = command.ExecuteScalar();
                        if (result != null)
                        {
                            ItemsSource.Add(new MusicDB()
                            {
                                ID = result.ToString(),
                                NameMusique = music.NameMusique,
                                Artiste = music.Artiste,
                                Album = music.Album,
                                Duration = this.formatDuration(music.Duration),
                                Path = music.Path
                            });
                        }
                    }
                }
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
            }
        }
        #endregion

        #region " Add Artiste - Album M/I "
        public string addArtiste(String Artiste)
        {
            try
            {
                SQLiteCommand command;
                command = new SQLiteCommand(SELECT_ID_FROM_DB_ARTIST, this.m_dbConnection);
                command.Parameters.AddWithValue("@artist", Artiste);
                SQLiteDataReader reader = command.ExecuteReader();
                if (reader.Read())
                    return reader["id"].ToString();
                command = new SQLiteCommand(INSERT_DB_ARTIST + SELECT_LAST_ROW, this.m_dbConnection);
                command.Parameters.AddWithValue("@name", Artiste);
                object result = command.ExecuteScalar();
                return result.ToString();
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return null;
            }
        }

        public string addAlbumMusique(String Album, String id_artist)
        {
            try
            {
                SQLiteCommand command = new SQLiteCommand(SELECT_ID_FROM_DB_ALBUM_MUSIC, this.m_dbConnection);
                command.Parameters.AddWithValue("@album", Album);
                SQLiteDataReader reader = command.ExecuteReader();
                if (reader.Read())
                    return reader["id"].ToString();
                command = new SQLiteCommand(INSERT_DB_ALBUM_MUSIC + SELECT_LAST_ROW, this.m_dbConnection);
                command.Parameters.AddWithValue("@name", Album);
                command.Parameters.AddWithValue("@idArtist", id_artist);
                object result = command.ExecuteScalar();
                return result.ToString();
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return null;
            }
        }

        public string addAlbumImage(String Album)
        {
            try
            {
                SQLiteCommand command;
                command = new SQLiteCommand(SELECT_ID_FROM_DB_ALBUM_IMAGE, this.m_dbConnection);
                command.Parameters.AddWithValue("@album", Album);
                SQLiteDataReader reader = command.ExecuteReader();
                if (reader.Read())
                    return reader["id"].ToString();
                command = new SQLiteCommand(INSERT_DB_ALBUM_IMAGE + SELECT_LAST_ROW, this.m_dbConnection);
                command.Parameters.AddWithValue("@name", Album);
                object result = command.ExecuteScalar();
                return result.ToString();
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
                return null;
            }
        }
        #endregion
        
        #region " Playlist features "
        /// <summary>
        /// Add a new playlist
        /// We will need to check if the playlist already exists
        /// </summary>
        /// <param name="name">Playlist name</param>
        /// <returns>String id</returns>
        public void addPlaylist(String name, ObservableCollection<PlaylistDB> itemSource)
        {
            try
            {
                SQLiteCommand command;
                command = new SQLiteCommand(INSERT_DB_PLAYLIST + SELECT_LAST_ROW, this.m_dbConnection);
                command.Parameters.AddWithValue("@name", name);
                object result = command.ExecuteScalar();
                if (result != null)
                {
                    itemSource.Add(new PlaylistDB()
                    {
                        ID = Int32.Parse(result.ToString()),
                        NamePlaylist = name,
                        MusicsList = new ObservableCollection<MusicDB>()

                    });
                }
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
            }
        }

        public void addMusicInPlaylist(PlaylistDB playlist, MusicDB music)
        {
            try
            {
                SQLiteCommand command;
                command = new SQLiteCommand(INSERT_DB_PLAYLIST_SONG + SELECT_LAST_ROW, this.m_dbConnection);
                command.Parameters.AddWithValue("@id_playlist", playlist.ID);
                command.Parameters.AddWithValue("@id_music", music.ID);
                object result = command.ExecuteScalar();
                if (result != null)
                {
                    playlist.MusicsList.Add(new MusicDB()
                    {
                        ID = music.ID,
                        NameMusique = music.NameMusique,
                        Artiste = music.Artiste,
                        Album = music.Album,
                        Duration = this.formatDuration(music.Duration),
                        Path = music.Path
                    });
                }
            }
            catch (Exception e)
            {
                if (e is UnauthorizedAccessException || e is SQLiteException)
                    Console.Error.WriteLine(e.Message);
            }
        }
        #endregion

        #region Utils
        private string formatDuration(string duration)
        {
            string[] splits = Regex.Split(duration, @"\D+");
            if (splits.Length != 4)
            {
                return duration;
            }
            else
            {
                string newSentence = splits[0] + ":" + splits[1] + ":" + splits[2];
                newSentence = Regex.Replace(newSentence, "^(00:|0)", "");
                return newSentence;
            }
        }
        #endregion

        #region " TableExists "
        private bool isTableExist(string DataBase)
        {
            try
            {
                string select = "SELECT id FROM " + DataBase;
                SQLiteCommand command = new SQLiteCommand(select, this.m_dbConnection);
                SQLiteDataReader reader = command.ExecuteReader();
            }
            catch (System.Data.SQLite.SQLiteException)
            {
                return false;
            }
            return true;
        }
        #endregion
    }
}
