using MyWindowsMediaPlayer.ViewModel;
using MyWindowsMediaPlayer.Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;
using System.Windows;
using MahApps.Metro.Controls.Dialogs;
using System.Windows.Forms;
using System.IO;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Threading;
using MahApps.Metro.Controls;
using MyWindowsMediaPlayer.Utils;
using ListView = System.Windows.Forms.ListView;

namespace MyWindowsMediaPlayer.ViewModel
{
    public class MainViewModel : ViewModelBase
    {
        public enum FormatMedia
        {
            Musique = 0,
            Video = 1,
            Image = 2,
            Drag = 3,
            Playlist = 4
        };
        public enum StateRepeat
        {
            NONE,
            ONE,
            ALL
        };
        public FormatMedia State;
        public StateRepeat RepeatState;
        private static readonly object Lock = new object();
        private readonly ListClick _listClick;
        private readonly SettingsFunction _settingsFunction;
        public ShowDialog ShowDialog;
        public ButtonFunction ButtonFunction;

        public MainViewModel()
        {
            var mainViewModel = this;
            this.ButtonFunction = new ButtonFunction(ref mainViewModel);
            this.ShowDialog = new ShowDialog(ref mainViewModel);
            this._listClick = new ListClick(ref mainViewModel);
            this._settingsFunction = new SettingsFunction(ref mainViewModel);

            this.MediaPlayer = new MediaElement();
            this.MediaPlayer.MediaEnded += MyMediaElementOnMediaEnded;
            this.MediaPlayer.LoadedBehavior = MediaState.Manual;
            this.Volume = this.MediaPlayer.Volume;
            this.VolumeVisibility = Visibility.Collapsed;

            this.ItemSourceSynchroFolder = new ObservableCollection<SynchronisationFolder>();
            this.ItemSourceMusic = DBBibliotheque.Instance.GetListMusique();
            this.ItemSourceVideo = DBBibliotheque.Instance.GetListVideo();
            this.ItemSourceImage = DBBibliotheque.Instance.GetListImage();
            this.ItemSourcePlaylist = DBBibliotheque.Instance.GetListPlaylists();
            this.ItemSourcePlaylistMusic = new ObservableCollection<MusicDB>();
            
            this.State = FormatMedia.Musique;
            this.RepeatState = StateRepeat.NONE;

            this.SourceImg = new BitmapImage(new Uri("../Ressources/play.png", UriKind.Relative));
            this.VolumeImage = new BitmapImage(new Uri("../Ressources/speaker_low.png", UriKind.Relative));
            this.RepeatSource = new BitmapImage(new Uri("../Ressources/repeat.png", UriKind.Relative));

            BindingOperations.EnableCollectionSynchronization(this.ItemSourceMusic, MainViewModel.Lock);
            BindingOperations.EnableCollectionSynchronization(this.ItemSourceImage, MainViewModel.Lock);
            BindingOperations.EnableCollectionSynchronization(this.ItemSourceVideo, MainViewModel.Lock);
            BindingOperations.EnableCollectionSynchronization(this.ItemSourcePlaylist, MainViewModel.Lock);

            DispatcherTimer timer = new DispatcherTimer {Interval = TimeSpan.FromSeconds(1)};
            timer.Tick += timer_Tick;
            timer.Start();

            EnterCommand = new CommandProvider(obj => this._settingsFunction.EnterCommand(obj));
            EnterCommand.GestureKey = Key.Enter;

            this.ItemSourcePlaylist.Add(new PlaylistDB() { ID = 0, NamePlaylist = "Créée une playlist", MusicsList = new ObservableCollection<MusicDB>()});
        }

        private MediaElement _mediaPlayer;
        public MediaElement MediaPlayer
        {
            get{ return _mediaPlayer; }
            set
            {
                _mediaPlayer = value;
                this.OnPropertyChanged("mediaElement");
            }
        }

        private ImageSource _sourceImgvm;
        public ImageSource SourceImg
        {
            get { return _sourceImgvm; }
            set
            {
                _sourceImgvm = value;
                this.OnPropertyChanged("SourceImg");
            }
        }

        private ImageSource _repeatSourceVm;
        public ImageSource RepeatSource
        {
            get { return this._repeatSourceVm; }
            set
            {
                this._repeatSourceVm = value;
                this.OnPropertyChanged("RepeatSource");
            }
        }

        private ImageSource _volumeImage;
        public ImageSource VolumeImage
        {
            get { return _volumeImage; }
            set
            {
                this._volumeImage = value;
                this.OnPropertyChanged("VolumeImage");
            }
        }

        private double _slideValue;
        public double SlideValue
        {
            get { return _slideValue; }
            set
            {
                _slideValue = value;
                this.OnPropertyChanged("SlideValue");
            }
        }

        private double _maximum;
        public double Maximum
        {
            get { return _maximum; }
            set
            {
                _maximum = value;
                this.OnPropertyChanged("Maximum");
            }
        }

        private double _minimun;
        public double Minimun
        {
            get { return _minimun; }
            set
            {
                _minimun = value;
                this.OnPropertyChanged("Maximum");
            }
        }

        private double _volume;
        public double Volume
        {
            get { return _volume; }
            set
            {
                this._volume = value;
                this.MediaPlayer.Volume = value;
                if (Math.Abs(value) > 0.5)
                    this.VolumeImage = new BitmapImage(new Uri("../Ressources/speaker_full.png", UriKind.Relative));
                else if (Math.Abs(value) <= 0.5 && Math.Abs(value) != 0.0)
                    this.VolumeImage = new BitmapImage(new Uri("../Ressources/speaker_low.png", UriKind.Relative));
                else if (Math.Abs(value) == 0.0)
                    this.VolumeImage = new BitmapImage(new Uri("../Ressources/speaker_mute.png", UriKind.Relative));
                this.OnPropertyChanged("Volume");
            }
        }

        private Visibility _volumeVisibility;
        public Visibility VolumeVisibility
        {
            get { return this._volumeVisibility; }
            set
            {
                this._volumeVisibility = value;
                this.OnPropertyChanged("VolumeVisibility");
            }
        }

        private Visibility _synchroRingVisibility;
        public Visibility SynchroRingVisibility
        {
            get { return _synchroRingVisibility; }
            set
            {
                this._synchroRingVisibility = value;
                this.OnPropertyChanged("SynchroRingVisibility");
            }
        }

        private int _itemIndexMusic;
        public int ItemIndexMusic
        {
            get { return _itemIndexMusic; }
            set
            {
                this._itemIndexMusic = value;
                this.OnPropertyChanged("ItemIndexMusic");
            }
        }

        private int _itemIndexVideo;
        public int ItemIndexVideo
        {
            get { return _itemIndexVideo; }
            set
            {
                this._itemIndexVideo = value;
                this.OnPropertyChanged("ItemIndexVideo");
            }
        }

        private int _itemIndexImage;
        public int ItemIndexImage
        {
            get { return this._itemIndexImage; }
            set
            {
                this._itemIndexImage = value;
                this.OnPropertyChanged("ItemIndexImage");
            }
        }

        private int _itemIndexPlaylist;
        public int ItemIndexPlaylist
        {
            get { return this._itemIndexPlaylist; }
            set
            {
                this._itemIndexPlaylist = value;
                this.OnPropertyChanged("ItemIndexPlaylist");
            }
        }

        private int _itemIndexDrag;
        public int ItemIndexDrag
        {
            get { return this._itemIndexDrag; }
            set
            {
                this._itemIndexDrag = value;
                this.OnPropertyChanged("ItemIndexDrag");
            }
        }

        private int _itemIndexPlaylistMusic;
        public int ItemIndexPlaylistMusic
        {
            get { return this._itemIndexPlaylistMusic; }
            set
            {
                this._itemIndexPlaylistMusic = value;
                this.OnPropertyChanged("ItemIndexPlaylistMusic");
            }
        }

        private MusicDB _itemSelectedMusic;
        public MusicDB ItemSelectedMusic
        {
            get { return _itemSelectedMusic; }
            set
            {
                _itemSelectedMusic = value;
                this.OnPropertyChanged("ItemSelectedMusic");
            }
        }

        private VideoDB _itemSelectedVideo;
        public VideoDB ItemSelectedVideo
        {
            get { return _itemSelectedVideo; }
            set
            {
                _itemSelectedVideo = value;
                this.OnPropertyChanged("ItemSelectedVideo");
            }
        }

        private ImageDB _itemSelectedImage;
        public ImageDB ItemSelectedImage
        {
            get { return _itemSelectedImage; }
            set
            {
                _itemSelectedImage = value;
                this.OnPropertyChanged("ItemSelectedImage");
            }
        }

        private PlaylistDB _itemSelectedPlaylist;
        public PlaylistDB ItemSelectedPlaylist
        {
            get { return this._itemSelectedPlaylist; }
            set
            {
                this._itemSelectedPlaylist = value;
                this.OnPropertyChanged("ItemSelectedPlaylist");
            }
        }

        private MusicDB _itemSelectedPlaylistMusic;
        public MusicDB ItemSelectedPlaylistMusic
        {
            get { return _itemSelectedPlaylistMusic; }
            set
            {
                _itemSelectedPlaylistMusic = value;
                this.OnPropertyChanged("ItemSelectedPlaylistMusic");
            }
        }

        private DragList _itemSelectedDrag;
        public DragList ItemSelectedDrag
        {
            get { return _itemSelectedDrag; }
            set
            {
                _itemSelectedDrag = value;
                this.OnPropertyChanged("ItemSelectedDrag");
            }
        }

        private Filter _itemSelectedSearch;
        public Filter ItemSelectedSearch
        {
            get { return _itemSelectedSearch; }
            set
            {
                _itemSelectedSearch = value;
                this.OnPropertyChanged("ItemSelectedSearch");
            }
        }

        public CommandProvider EnterCommand { get; set; }

        public ICommand FlyoutOc { get { return new CommandProvider(obj => this._settingsFunction.FlyoutFunction()); } }

        public ICommand CurrentPlaylist { get { return new CommandProvider(obj => this._settingsFunction.CurrentPlaylist()); } }

        public ICommand TestCall { get { return new CommandProvider(obj => this._settingsFunction.AddMusiqueInPlaylistFunction(obj)); } }

        public ICommand SyncroFolderAdd { get { return new CommandProvider(obj => this._settingsFunction.SynchroFolderAddFunction()); } }

        public ICommand FolderBoxDoubleClick { get { return new CommandProvider(obj => this._settingsFunction.FolderBoxDoubleClickFunction()); } }

        public ICommand SearchFolder { get { return new CommandProvider(obj => this._settingsFunction.SearchFolderFunction()); } }

        public ICommand SearchComputer { get { return new CommandProvider(obj => this._settingsFunction.SearchComputerFunction()); } }

        public ICommand DragCompleted { get { return new CommandProvider(obj => this._settingsFunction.DragCompletedFunction()); } }

        public ICommand ListVideoDoubleClick { get { return new CommandProvider(obj => this._listClick.ListVideoDoubleClickFunction()); } }

        public ICommand ListMusicDoubleClick { get { return new CommandProvider(obj => this._listClick.ListMusicDoubleClickFunction()); } }

        public ICommand ListImageDoubleClick { get { return new CommandProvider(obj => this._listClick.ListImageDoubleClickFunction()); } }

        public ICommand ListPlaylistDoubleClick { get { return new CommandProvider(obj => this._listClick.ListPlaylistDoubleClickFunction()); } }

        public ICommand ListPlaylistMusicDoubleClick { get { return new CommandProvider(obj => this._listClick.ListPlaylistMusicDoubleClickFunction()); } }

        public ICommand ListSearchDoubleClick { get { return new CommandProvider(obj => this._listClick.ListSearchDoubleClickFunction()); } }

        public ICommand ListDragDoubleClick { get { return new CommandProvider(obj => this._listClick.ListDragDoubleClickFunction()); } }

        public ICommand VolumeCommand { get { return new CommandProvider(obj => this._settingsFunction.VolumeFunction()); } }

        public ICommand PlayCommand { get { return new CommandProvider(obj => this.ButtonFunction.PlayFunction()); } }

        public ICommand StopCommand { get { return new CommandProvider(obj => this.ButtonFunction.StopFunction()); } }

        public ICommand LeftCommand { get { return new CommandProvider(obj => this.ButtonFunction.LeftFunction()); } }

        public ICommand RightCommand { get { return new CommandProvider(obj => this.ButtonFunction.RightFunction()); } }

        public ICommand RepeatCommand { get { return new CommandProvider(obj => this.ButtonFunction.RepeatFunction()); } }

        private ObservableCollection<SynchronisationFolder> _itemSourceSynchroFolder;
        public ObservableCollection<SynchronisationFolder> ItemSourceSynchroFolder
        {
            get { return _itemSourceSynchroFolder; }
            set
            {
                _itemSourceSynchroFolder = value;
                this.OnPropertyChanged("ItemSourceSynchroFolder");
            }
        }

        private ObservableCollection<MusicDB> _itemSourceMusic;
        public ObservableCollection<MusicDB> ItemSourceMusic
        {
            get { return _itemSourceMusic; }
            set
            {
                _itemSourceMusic = value;
                this.OnPropertyChanged("ItemSourceMusic");
            }
        }

        private ObservableCollection<VideoDB> _itemSourceVideo;
        public ObservableCollection<VideoDB> ItemSourceVideo
        {
            get { return _itemSourceVideo; }
            set
            {
                _itemSourceVideo = value;
                this.OnPropertyChanged("ItemSourceVideo");
            }
        }

        private ObservableCollection<ImageDB> _itemSourceImage;
        public ObservableCollection<ImageDB> ItemSourceImage
        {
            get { return _itemSourceImage; }
            set
            {
                _itemSourceImage = value;
                this.OnPropertyChanged("ItemSourceImage");
            }
        }

        private ObservableCollection<PlaylistDB> _itemSourcePlaylist;
        public ObservableCollection<PlaylistDB> ItemSourcePlaylist
        {
            get { return this._itemSourcePlaylist; }
            set
            {
                this._itemSourcePlaylist = value;
                this.OnPropertyChanged("ItemSourcePlaylist");
            }
        }

        private ObservableCollection<MusicDB> _itemSourcePlaylistMusic;
        public ObservableCollection<MusicDB> ItemSourcePlaylistMusic
        {
            get { return _itemSourcePlaylistMusic; }
            set
            {
                _itemSourcePlaylistMusic = value;
                this.OnPropertyChanged("ItemSourcePlaylistMusic");
            }
        }

        private ObservableCollection<DragList> _itemSourceDrag;
        public ObservableCollection<DragList> ItemSourceDrag
        {
            get { return _itemSourceDrag; }
            set
            {
                _itemSourceDrag = value;
                this.OnPropertyChanged("ItemSourceDrag");
            }
        }

        private ObservableCollection<Filter> _itemSourceSearch;
        public ObservableCollection<Filter> ItemSourceSearch
        {
            get { return _itemSourceSearch; }
            set
            {
                _itemSourceSearch = value;
                this.OnPropertyChanged("ItemSourceSearch");
            }
        }

        private bool _synchroRing;
        public bool SynchroRing
        {
            get { return _synchroRing; }
            set
            {
                this._synchroRing = value;
                this.OnPropertyChanged("SynchroRing");
            }
        }

        private bool _musiqueCheck;
        public bool MusiqueCheck
        {
            get { return _musiqueCheck; }
            set
            {
                _musiqueCheck = value;
                this.OnPropertyChanged("MusiqueCheck");
            }
        }

        private bool _videoCheck;
        public bool VideoCheck
        {
            get { return _videoCheck; }
            set
            {
                _videoCheck = value;
                this.OnPropertyChanged("VideoCheck");
            }
        }

        private bool _imageCheck;
        public bool ImageCheck
        {
            get { return _imageCheck; }
            set
            {
                _imageCheck = value;
                this.OnPropertyChanged("ImageCheck");
            }
        }

        private bool _recursion;
        public bool Recursion
        {
            get { return _recursion; }
            set
            {
                _recursion = value;
                this.OnPropertyChanged("Recursion");
            }
        }

        private bool _flyoutBool;
        public bool FlyoutBool
        {
            get { return _flyoutBool; }
            set
            {
                this._flyoutBool = value;
                this.OnPropertyChanged("FlyoutBool");
            }
        }

        private bool _flyoutBoolDrag;
        public bool FlyoutBoolDrag
        {
            get { return _flyoutBoolDrag; }
            set
            {
                this._flyoutBoolDrag = value;
                this.OnPropertyChanged("FlyoutBoolDrag");
            }
        }

        private bool _repeatChecked;
        public bool RepeatChecked
        {
            get { return _repeatChecked; }
            set
            {
                this._repeatChecked = value;
                this.OnPropertyChanged("RepeatChecked");
            }
        }

        private bool _randomChecked;
        public bool RandomChecked
        {
            get { return this._randomChecked; }
            set
            {
                this._randomChecked = value;
                this.OnPropertyChanged("RandomChecked");
            }
        }

        private bool _selectMediaElement;
        public bool SelectMediaElement
        {
            get { return _selectMediaElement; }
            set
            {
                this._selectMediaElement = value;
                this.OnPropertyChanged("SelectMediaElement");
            }
        }

        private bool _tmpPlaylist;
        public bool TmpPlaylist
        {
            get { return _tmpPlaylist; }
            set
            {
                this._tmpPlaylist = value;
                this.OnPropertyChanged("TmpPlaylist");
            }
        }

        private bool _albumCheck;
        public bool AlbumCheck
        {
            get { return _albumCheck; }
            set
            {
                this._albumCheck = value;
                this.OnPropertyChanged("AlbumCheck");
            }
        }

        private bool _artisteCheck;
        public bool ArtisteCheck
        {
            get { return _artisteCheck; }
            set
            {
                this._artisteCheck = value;
                this.OnPropertyChanged("ArtisteCheck");
            }
        }

        private bool _nameCheck;
        public bool NameCheck
        {
            get { return _nameCheck; }
            set
            {
                this._nameCheck = value;
                this.OnPropertyChanged("NameCheck");
            }
        }

        private bool _searchChecked;
        public bool SearchChecked
        {
            get { return _searchChecked; }
            set
            {
                this._searchChecked = value;
                this.OnPropertyChanged("SearchChecked");
            }
        }

        private bool _temporaireChecked;
        public bool TemporaireChecked
        {
            get { return _temporaireChecked; }
            set
            {
                this._temporaireChecked = value;
                this.OnPropertyChanged("TemporaireChecked");
            }
        }

        private string _folderBox;
        public string FolderBox
        {
            get { return _folderBox; }
            set
            {
                _folderBox = value;
                this.OnPropertyChanged("FolderBox");
            }
        }

        private string _namePlaylistMusicSelected;
        public string NamePlaylistMusicSelected
        {
            get { return this._namePlaylistMusicSelected; }
            set
            {
                this._namePlaylistMusicSelected = value;
                this.OnPropertyChanged("NamePlaylistMusicSelected");
            }
        }

        private string _textSearch;
        public string TextSearch
        {
            get { return _textSearch; }
            set
            {
                this._textSearch = value;
                this.OnPropertyChanged("TextSearch");
            }
        }

        private void timer_Tick(object sender, EventArgs e)
        {
            if (this.MediaPlayer.Source != null && this.MediaPlayer.NaturalDuration.HasTimeSpan)
            {
                Minimun = 0;
                Maximum = this.MediaPlayer.NaturalDuration.TimeSpan.TotalSeconds;
                SlideValue = this.MediaPlayer.Position.TotalSeconds;
            }
        }

        private void MyMediaElementOnMediaEnded(object sender, RoutedEventArgs routedEventArgs)
        {
            Random rand = new Random();
            switch (this.RepeatState)
            {
                case StateRepeat.NONE:
                    this.ButtonFunction.RightFunction();
                    break;
                case StateRepeat.ONE:
                    this.MediaPlayer.Position = TimeSpan.Zero;
                    this.MediaPlayer.Play();
                    break;
                case StateRepeat.ALL:
                    #region " Repeat All "
                    {
                        switch (State)
                        {
                            case FormatMedia.Musique:
                                if (ItemIndexMusic == ItemSourceMusic.Count - 1)
                                {
                                    ItemIndexMusic = (RandomChecked) ? rand.Next(0, ItemSourceMusic.Count) : 0;
                                    ItemSelectedMusic = ItemSourceMusic[ItemIndexMusic];
                                    this.MediaPlayer.Source = new Uri(ItemSelectedMusic.Path);
                                }
                                break;
                            case FormatMedia.Video:
                                if (ItemIndexVideo == ItemSourceVideo.Count - 1)
                                {
                                    ItemIndexVideo = (RandomChecked) ? rand.Next(0, ItemSourceVideo.Count) : 0;
                                    ItemSelectedVideo = ItemSourceVideo[ItemIndexVideo];
                                    this.MediaPlayer.Source = new Uri(ItemSelectedVideo.Path);
                                }
                                break;
                            case FormatMedia.Image:
                                if (ItemIndexImage == ItemSourceImage.Count - 1)
                                {
                                    ItemIndexImage = (RandomChecked) ? rand.Next(0, ItemSourceImage.Count) : 0;
                                    ItemSelectedImage = ItemSourceImage[ItemIndexImage];
                                    this.MediaPlayer.Source = new Uri(ItemSelectedImage.Path);
                                }
                                break;
                            case FormatMedia.Drag:
                                if (ItemIndexDrag == ItemSourceDrag.Count - 1)
                                {
                                    ItemIndexDrag = (RandomChecked) ? rand.Next(0, ItemSourceDrag.Count) : 0;
                                    ItemSelectedDrag = ItemSourceDrag[ItemIndexDrag];
                                    this.MediaPlayer.Source = new Uri(ItemSelectedDrag.Path);
                                }
                                break;
                            case FormatMedia.Playlist:
                                if (ItemIndexPlaylistMusic == ItemSourcePlaylistMusic.Count - 1)
                                {
                                    ItemIndexPlaylistMusic = (RandomChecked) ? rand.Next(0, ItemSourcePlaylistMusic.Count) : 0;
                                    ItemSelectedPlaylistMusic = ItemSourcePlaylistMusic[ItemIndexPlaylistMusic];
                                    this.MediaPlayer.Source = new Uri(ItemSelectedPlaylistMusic.Path);
                                }
                                break;
                        }
                        this.MediaPlayer.Play();
                        this.SourceImg = new BitmapImage(new Uri("../Ressources/play.png", UriKind.Relative));
                    }
                    #endregion
                    break;
            }
        }
    }
}
