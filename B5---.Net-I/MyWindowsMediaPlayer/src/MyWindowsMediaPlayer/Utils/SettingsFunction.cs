using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Forms;
using System.Windows.Media.Animation;
using MyWindowsMediaPlayer.Model;
using MyWindowsMediaPlayer.ViewModel;
using File = TagLib.File;

namespace MyWindowsMediaPlayer.Utils
{
    public class SettingsFunction
    {
        private readonly List<string> _imageExtension = new List<string>() { ".jpg", ".png", ".jpeg" };
        private readonly List<string> _videoExtension = new List<string>() { ".avi", ".mp4" };
        private readonly List<string> _musiqueExtension = new List<string>() { ".mp3", ".wav" };
        private readonly MainViewModel _mainView;

        public SettingsFunction(ref MainViewModel mainView)
        {
            this._mainView = mainView;
        }

        public void ActiveSynchroRing()
        {
            this._mainView.SynchroRing = true;
            this._mainView.SynchroRingVisibility = Visibility.Visible;
        }

        public void DesactiveSynchroRing()
        {
            this._mainView.SynchroRing = false;
            this._mainView.SynchroRingVisibility = Visibility.Collapsed;
        }

        public void FlyoutFunction()
        {
            this._mainView.FlyoutBool = !this._mainView.FlyoutBool;
        }

        private List<string> CheckCheckBox()
        {
            try
            {
                List<string> tmp = new List<string>();
                if (this._mainView.MusiqueCheck)
                    tmp.InsertRange(0, this._musiqueExtension);
                if (this._mainView.VideoCheck)
                    tmp.InsertRange(tmp.Count, this._videoExtension);
                if (this._mainView.ImageCheck)
                    tmp.InsertRange(tmp.Count, this._imageExtension);
                return tmp;
            }
            catch (InvalidOperationException e)
            {
                Console.Write(e.ToString());
            }
            return null;
        }

        private void AddMedia(string f)
        {
            try
            {
                File tagFile = File.Create(f);
                try
                {
                    if (this._musiqueExtension.Contains(Path.GetExtension(f)))

                    #region " Add Musique "

                    {
                        DBBibliotheque.Instance.addMusique(new MusicDB()
                        {
                            NameMusique =
                                (tagFile.Tag.Title ?? Path.GetFileName(f)),
                            Path = f,
                            Duration = tagFile.Properties.Duration.ToString(),
                            Artiste = (tagFile.Tag.FirstAlbumArtist ?? "Unknown"),
                            Album = (tagFile.Tag.Album ?? "Unknown")
                        }, this._mainView.ItemSourceMusic);
                    }
                    #endregion

                    else if (this._videoExtension.Contains(Path.GetExtension(f)))

                    #region " Add Video "

                    {
                        DBBibliotheque.Instance.addVideo(new VideoDB()
                        {
                            NameVideo =
                                (tagFile.Tag.Title ?? Path.GetFileName(f)),
                            Path = f,
                            Duration = tagFile.Properties.Duration.ToString()
                        }, this._mainView.ItemSourceVideo);
                    }
                    #endregion

                    else if (this._imageExtension.Contains(Path.GetExtension(f)))

                    #region " Add Image "

                    {
                        DBBibliotheque.Instance.addImage(new ImageDB()
                        {
                            NameImage =
                                (tagFile.Tag.Title ?? Path.GetFileName(f)),
                            Path = f,
                            Album = (tagFile.Tag.Album ?? "Unknown")
                        }, this._mainView.ItemSourceImage);
                    }

                    #endregion
                }
                catch (UnauthorizedAccessException exception)
                {
                    this._mainView.ShowDialog.ErrorMetroWindow(exception.Message, null);
                }
            }
            catch (TagLib.CorruptFileException)
            {
                if (this._musiqueExtension.Contains(Path.GetExtension(f)))
                {
                    DBBibliotheque.Instance.addMusique(new MusicDB()
                    {
                        NameMusique = Path.GetFileName(f),
                        Path = f,
                        Album = "Unknown",
                        Artiste = "Unknown"
                    }, this._mainView.ItemSourceMusic);
                }
                else if (this._videoExtension.Contains(Path.GetExtension(f)))
                {
                    DBBibliotheque.Instance.addVideo(new VideoDB()
                    {
                        NameVideo = Path.GetFileName(f),
                        Path = f
                    }, this._mainView.ItemSourceVideo);
                }
                else if (this._imageExtension.Contains(Path.GetExtension(f)))
                {
                    DBBibliotheque.Instance.addImage(new ImageDB()
                    {
                        NameImage = Path.GetFileName(f),
                        Path = f,
                        Album = "Unknown"
                    }, this._mainView.ItemSourceImage);
                }
            }
        }

        private void Search(string mDir, List<string> mediaExtensions)
        {
            try
            {
                foreach (string d in Directory.GetDirectories(mDir))
                {
                    try
                    {
                        foreach (string f in Directory.GetFiles(d, "*.*"))
                        {
                            if (mediaExtensions.Contains(Path.GetExtension(f).ToLower()))
                                this.AddMedia(f);
                            Search(d, mediaExtensions);
                        }
                    }
                    catch (Exception excpt)
                    {
                        Console.WriteLine(excpt.Message);
                    }
                }
            }
            catch (IOException excpt)
            {
                Console.WriteLine(excpt.Message);
            }
        }

        public async void SearchComputerFunction()
        {
            List<string> mediaExtensions = CheckCheckBox();

            this.FlyoutFunction();
            this.ActiveSynchroRing();
            if (mediaExtensions != null && mediaExtensions.Count > 0)
            {
                await Task.Run(() =>
                {
                    foreach (string d in Directory.GetLogicalDrives())
                    {
                        this.Search(d, mediaExtensions);
                    }
                });
            }
            this.DesactiveSynchroRing();
        }

        public async void SearchFolderFunction()
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            List<string> mediaExtensions = CheckCheckBox();

            if (mediaExtensions != null && mediaExtensions.Count > 0)
                if (fbd.ShowDialog() != DialogResult.Cancel)
                {
                    this.FlyoutFunction();
                    this.ActiveSynchroRing();
                    await Task.Run(() =>
                    {
                        try
                        {
                            foreach (string f in Directory.GetFiles(fbd.SelectedPath, "*.*"))
                                if (mediaExtensions.Contains(Path.GetExtension(f).ToLower()))
                                    this.AddMedia(f);
                            if (this._mainView.Recursion)
                                foreach (string d in Directory.GetDirectories(fbd.SelectedPath))
                                    foreach (string f in Directory.GetFiles(d, "*.*"))
                                        if (mediaExtensions.Contains(Path.GetExtension(f).ToLower()))
                                            this.AddMedia(f);
                        }
                        catch (Exception excpt)
                        {
                            Console.WriteLine(excpt.ToString());
                        }
                    });
                    this.DesactiveSynchroRing();
                }
        }

        public void VolumeFunction()
        {
            this._mainView.VolumeVisibility = (this._mainView.VolumeVisibility == Visibility.Visible) ? Visibility.Collapsed : Visibility.Visible;
        }

        public void FolderBoxDoubleClickFunction()
        {
            FolderBrowserDialog fbd = new FolderBrowserDialog();
            if (fbd.ShowDialog() != System.Windows.Forms.DialogResult.Cancel)
                this._mainView.FolderBox = fbd.SelectedPath;
        }

        public void SynchroFolderAddFunction()
        {
            if (this._mainView.FolderBox != "")
            {
                bool canAdd = true;
                foreach (SynchronisationFolder itemRow in this._mainView.ItemSourceSynchroFolder)
                {
                    if (itemRow.PathFolder.Equals(this._mainView.FolderBox))
                        canAdd = false;
                }
                if (canAdd)
                    this._mainView.ItemSourceSynchroFolder.Add(new SynchronisationFolder() { PathFolder = this._mainView.FolderBox });
                this._mainView.FolderBox = "";
            }
        }

        public void DragCompletedFunction()
        {
            this._mainView.MediaPlayer.Position = TimeSpan.FromSeconds(this._mainView.SlideValue);
        }

        public void AddMusiqueInPlaylistFunction(object o)
        {
            var tmp = o as string;
            if (!tmp.Equals("Créée une playlist"))
            {
                try
                {
                    PlaylistDB playlistDb = null;
                    foreach (PlaylistDB tmpPlaylistDb in this._mainView.ItemSourcePlaylist)
                    {
                        if (tmpPlaylistDb.NamePlaylist.Equals(tmp))
                            playlistDb = tmpPlaylistDb;
                    }
                    if (playlistDb != null)
                        DBBibliotheque.Instance.addMusicInPlaylist(playlistDb, this._mainView.ItemSelectedMusic);
                }
                catch (UnauthorizedAccessException e)
                {
                    this._mainView.ShowDialog.ErrorMetroWindow(e.Message);
                }
            }
        }

        public void EnterCommand(object sender)
        {
            this._mainView.SearchChecked = true;
            this._mainView.ItemSourceSearch = DBBibliotheque.Instance.getSearchItems(this._mainView.TextSearch,
                new CheckFilter()
                {
                    Album = this._mainView.AlbumCheck,
                    Artist = this._mainView.ArtisteCheck,
                    Name = this._mainView.NameCheck
                });
        }

        public void CurrentPlaylist()
        {
            this._mainView.FlyoutBoolDrag = !this._mainView.FlyoutBoolDrag;
        }
    }
}
