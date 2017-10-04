using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Media;
using MahApps.Metro.Controls;
using MahApps.Metro.Controls.Dialogs;
using MyWindowsMediaPlayer.Model;
using MyWindowsMediaPlayer.Utils;
using Application = System.Windows.Application;
using Button = System.Windows.Forms.Button;
using ListViewItem = System.Windows.Forms.ListViewItem;
using OpenFileDialog = Microsoft.Win32.OpenFileDialog;
using Path = System.IO.Path;
using TextBox = System.Windows.Forms.TextBox;
using MyWindowsMediaPlayer.ViewModel;
using File = TagLib.File;

namespace MyWindowsMediaPlayer
{
    /// <summary>
    /// Logique d'interaction pour MainWindow.xaml
    /// </summary>
    public partial class MainWindow : MetroWindow
    {
        private readonly List<string> _imageExtension = new List<string>() { ".jpg", ".png", ".jpeg" };
        private readonly List<string> _videoExtension = new List<string>() { ".avi", ".mp4" };
        private readonly List<string> _musiqueExtension = new List<string>() { ".mp3", ".wav" };
        private ObservableCollection<DragList> _collection;
        private SettingsFunction _settings;
        private readonly MainViewModel _mainView;

        public MainWindow()
        {
            InitializeComponent();

            this._mainView = new MainViewModel();

            this.AllowDrop = true;
            this.Loaded += MainWindow_Loaded;
            this.DragOver += MainWindow_DragDrop;
        }

        void MainWindow_Loaded(object sender, RoutedEventArgs e)
        {
            this.DataContext = this._mainView;
        }

        void MainWindow_DragDrop(object obj, DragEventArgs e)
        {
            if (e.Data.GetDataPresent(DataFormats.FileDrop))
            {
                this._mainView.TemporaireChecked = true;
                MainViewModel.FormatMedia tmpFormat = MainViewModel.FormatMedia.Musique;
                this._mainView.ItemSourceDrag = new ObservableCollection<DragList>();
                string[] files = (string[]) e.Data.GetData(DataFormats.FileDrop);
                foreach (string file in files)
                {
                    if (this._musiqueExtension.Contains(Path.GetExtension(file)))
                        tmpFormat = MainViewModel.FormatMedia.Musique;
                    else if (this._videoExtension.Contains(Path.GetExtension(file)))
                        tmpFormat = MainViewModel.FormatMedia.Video;
                    else if (this._imageExtension.Contains(Path.GetExtension(file)))
                        tmpFormat = MainViewModel.FormatMedia.Image;
                    this._mainView.ItemSourceDrag.Add(new DragList() { Name = Path.GetFileName(file), type = tmpFormat, Path = file });
                }
            }
        }
    }
}
