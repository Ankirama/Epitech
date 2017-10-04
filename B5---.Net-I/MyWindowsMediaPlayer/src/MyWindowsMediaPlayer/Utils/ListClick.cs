using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Imaging;
using MyWindowsMediaPlayer.Model;
using MyWindowsMediaPlayer.ViewModel;

namespace MyWindowsMediaPlayer.Utils
{
    public class ListClick
    {
        private readonly MainViewModel _mainView;

        public ListClick(ref MainViewModel mainView)
        {
            this._mainView = mainView;
        }

        public void ListImageDoubleClickFunction()
        {
            ImageDB music = this._mainView.ItemSelectedImage;
            if (this._mainView.MediaPlayer.IsBuffering)
                this._mainView.MediaPlayer.Stop();
            if (music.Path != null)
                this._mainView.MediaPlayer.Source = new Uri(music.Path);
            this._mainView.SelectMediaElement = true;
            this._mainView.ButtonFunction.PlayState();
            this._mainView.State = MainViewModel.FormatMedia.Image;
        }

        public void ListMusicDoubleClickFunction()
        {
            MusicDB music = this._mainView.ItemSelectedMusic;
            if (this._mainView.MediaPlayer.IsBuffering)
                this._mainView.MediaPlayer.Stop();
            if (music.Path != null)
                this._mainView.MediaPlayer.Source = new Uri(music.Path);
            this._mainView.ButtonFunction.PlayState();
            this._mainView.SelectMediaElement = true;
            this._mainView.State = MainViewModel.FormatMedia.Musique;
        }

        public void ListVideoDoubleClickFunction()
        {
            VideoDB music = this._mainView.ItemSelectedVideo;
            if (this._mainView.MediaPlayer.IsBuffering)
                this._mainView.MediaPlayer.Stop();
            if (music.Path != null)
                this._mainView.MediaPlayer.Source = new Uri(music.Path);
            this._mainView.ButtonFunction.PlayState();
            this._mainView.SelectMediaElement = true;
            this._mainView.State = MainViewModel.FormatMedia.Video;
        }

        public async void ListPlaylistDoubleClickFunction()
        {
            PlaylistDB playlist = this._mainView.ItemSelectedPlaylist;
            if (playlist.NamePlaylist.Equals("Créée une playlist"))
            {
                string tmp = await this._mainView.ShowDialog.ShowInputDialog("Nouvelle playlist", "Nom de la playlist");
                if (tmp != null)
                    DBBibliotheque.Instance.addPlaylist(tmp, this._mainView.ItemSourcePlaylist);
            }
            else
            {
                this._mainView.NamePlaylistMusicSelected = playlist.NamePlaylist;
                this._mainView.FlyoutBoolDrag = true;
                this._mainView.ItemSourcePlaylistMusic = playlist.MusicsList;
            }
        }

        public void ListDragDoubleClickFunction()
        {
            DragList drag = this._mainView.ItemSelectedDrag;
            if (this._mainView.MediaPlayer.IsBuffering)
                this._mainView.MediaPlayer.Stop();
            if (drag.Path != null)
                this._mainView.MediaPlayer.Source = new Uri(drag.Path);
            this._mainView.ButtonFunction.PlayState();
            this._mainView.SelectMediaElement = true;
            this._mainView.State = MainViewModel.FormatMedia.Drag;
        }

        public void ListPlaylistMusicDoubleClickFunction()
        {
            MusicDB music = this._mainView.ItemSelectedMusic;
            if (this._mainView.MediaPlayer.IsBuffering)
                this._mainView.MediaPlayer.Stop();
            if (music.Path != null)
                this._mainView.MediaPlayer.Source = new Uri(music.Path);
            this._mainView.ButtonFunction.PlayState();
            this._mainView.SelectMediaElement = true;
            this._mainView.State = MainViewModel.FormatMedia.Playlist;
        }

        public void ListSearchDoubleClickFunction()
        {
            Filter filter = this._mainView.ItemSelectedSearch;
            this._mainView.MediaPlayer.Source = new Uri(filter.Path);
            this._mainView.ButtonFunction.PlayState();
            switch (filter.Format)
            {
                case MainViewModel.FormatMedia.Musique:
                    break;
                case MainViewModel.FormatMedia.Image:
                    this._mainView.SelectMediaElement = true;
                    break;
                case MainViewModel.FormatMedia.Video:
                    this._mainView.SelectMediaElement = true;
                    break;
            }
        }
    }
}
