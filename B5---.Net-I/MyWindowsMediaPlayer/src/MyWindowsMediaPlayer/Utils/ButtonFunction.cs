using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;
using System.Windows.Media.Imaging;
using MyWindowsMediaPlayer.ViewModel;
using TagLib.IFD.Tags;

namespace MyWindowsMediaPlayer.Utils
{
    public class ButtonFunction
    {
        private readonly MainViewModel _viewModel;
        public bool MediaPlayerIsPlaying = false;

        public ButtonFunction(ref MainViewModel viewModel)
        {
            this._viewModel = viewModel;
        }

        public void StopFunction()
        {
            if (MediaPlayerIsPlaying)
                this._viewModel.MediaPlayer.Stop();
            MediaPlayerIsPlaying = false;
        }

        public void PlayFunction()
        {
            if (this._viewModel.MediaPlayer != null && this._viewModel.MediaPlayer.IsLoaded)
            {
                if (MediaPlayerIsPlaying)
                    this.PauseState();
                else
                    this.PlayState();
            }
        }

        public void RightFunction()
        {
            Random rand = new Random();
            switch (this._viewModel.State)
            {
                case MainViewModel.FormatMedia.Musique:
                    #region " Musique "
                    if (this._viewModel.ItemIndexMusic + 1 < this._viewModel.ItemSourceMusic.Count)
                    {
                        this._viewModel.ItemIndexMusic = (this._viewModel.RandomChecked) ? rand.Next(0, this._viewModel.ItemSourceMusic.Count) : this._viewModel.ItemIndexMusic + 1;
                        this._viewModel.ItemSelectedMusic = this._viewModel.ItemSourceMusic[this._viewModel.ItemIndexMusic];
                        this._viewModel.MediaPlayer.Stop();
                        this._viewModel.MediaPlayer.Source = new Uri(this._viewModel.ItemSelectedMusic.Path);
                        this.PlayState();
                    }
                    #endregion
                    break;
                case MainViewModel.FormatMedia.Video:
                    #region " Video "
                    if (this._viewModel.ItemIndexVideo + 1 < this._viewModel.ItemSourceVideo.Count)
                    {
                        this._viewModel.ItemIndexVideo = (this._viewModel.RandomChecked) ? rand.Next(0, this._viewModel.ItemSourceVideo.Count) : this._viewModel.ItemIndexVideo + 1;
                        this._viewModel.ItemSelectedVideo = this._viewModel.ItemSourceVideo[this._viewModel.ItemIndexVideo];
                        this._viewModel.MediaPlayer.Stop();
                        this._viewModel.MediaPlayer.Source = new Uri(this._viewModel.ItemSelectedVideo.Path);
                        this.PlayState();
                    }
                    #endregion
                    break;
                case MainViewModel.FormatMedia.Image:
                    #region " Image "
                    if (this._viewModel.ItemIndexImage + 1 <this._viewModel.ItemSourceImage.Count)
                    {
                        this._viewModel.ItemIndexImage = (this._viewModel.RandomChecked) ? rand.Next(0, this._viewModel.ItemSourceImage.Count) : this._viewModel.ItemIndexImage + 1;
                        this._viewModel.ItemSelectedImage = this._viewModel.ItemSourceImage[this._viewModel.ItemIndexImage];
                        this._viewModel.MediaPlayer.Stop();
                        this._viewModel.MediaPlayer.Source = new Uri(this._viewModel.ItemSelectedImage.Path);
                        this.PlayState();
                    }
                    #endregion
                    break;
                case MainViewModel.FormatMedia.Drag:
                    #region " Drag "
                    if (this._viewModel.ItemIndexDrag + 1 < this._viewModel.ItemSourceDrag.Count)
                    {
                        this._viewModel.ItemIndexDrag = (this._viewModel.RandomChecked) ? rand.Next(0, this._viewModel.ItemSourceDrag.Count) : this._viewModel.ItemIndexDrag + 1;
                        this._viewModel.ItemSelectedDrag = this._viewModel.ItemSourceDrag[this._viewModel.ItemIndexDrag];
                        this._viewModel.MediaPlayer.Stop();
                        this._viewModel.MediaPlayer.Source = new Uri(this._viewModel.ItemSelectedDrag.Path);
                        this.PlayState();
                    }
                    #endregion
                    break;
                case MainViewModel.FormatMedia.Playlist:
                    #region " Playlist "
                    if (this._viewModel.ItemIndexPlaylistMusic + 1 < this._viewModel.ItemSourcePlaylistMusic.Count)
                    {
                        this._viewModel.ItemIndexPlaylistMusic = (this._viewModel.RandomChecked) ? rand.Next(0, this._viewModel.ItemSourcePlaylistMusic.Count) : this._viewModel.ItemIndexPlaylistMusic + 1;
                        this._viewModel.ItemSelectedPlaylistMusic = this._viewModel.ItemSourcePlaylistMusic[this._viewModel.ItemIndexPlaylistMusic];
                        this._viewModel.MediaPlayer.Stop();
                        this._viewModel.MediaPlayer.Source = new Uri(this._viewModel.ItemSelectedPlaylistMusic.Path);
                        this.PlayState();
                    }
                    #endregion
                    break;
            }
        }

        public void LeftFunction()
        {
            switch (this._viewModel.State)
            {
                case MainViewModel.FormatMedia.Musique:
                    #region " Musique "
                    if (this._viewModel.ItemIndexMusic - 1 >= 0)
                    {
                        this._viewModel.ItemIndexMusic -= 1;
                        this._viewModel.ItemSelectedMusic = this._viewModel.ItemSourceMusic[this._viewModel.ItemIndexMusic];
                        this._viewModel.MediaPlayer.Source = new Uri(this._viewModel.ItemSelectedMusic.Path);
                        this.PlayState();
                    }
                    #endregion
                    break;
                case MainViewModel.FormatMedia.Video:
                    #region " Video "
                    if (this._viewModel.ItemIndexVideo - 1 >= 0)
                    {
                        this._viewModel.ItemIndexVideo -= 1;
                        this._viewModel.ItemSelectedVideo = this._viewModel.ItemSourceVideo[this._viewModel.ItemIndexVideo];
                        this._viewModel.MediaPlayer.Source = new Uri(this._viewModel.ItemSelectedVideo.Path);
                        this.PlayState();
                    }
                    #endregion
                    break;
                case MainViewModel.FormatMedia.Image:
                    #region " Image "
                    if (this._viewModel.ItemIndexImage - 1 >= 0)
                    {
                        this._viewModel.ItemIndexImage -= 1;
                        this._viewModel.ItemSelectedImage = this._viewModel.ItemSourceImage[this._viewModel.ItemIndexImage];
                        this._viewModel.MediaPlayer.Source = new Uri(this._viewModel.ItemSelectedImage.Path);
                        this.PlayState();
                    }
                    #endregion
                    break;
            }
        }

        public void RepeatFunction()
        {
            switch (this._viewModel.RepeatState)
            {
                case MainViewModel.StateRepeat.NONE:
                    this._viewModel.RepeatChecked = true;
                    this._viewModel.RepeatState = MainViewModel.StateRepeat.ONE;
                    this._viewModel.RepeatSource = new BitmapImage(new Uri("../Ressources/repeat_one.png", UriKind.Relative));
                    break;
                case MainViewModel.StateRepeat.ONE:
                    this._viewModel.RepeatChecked = true;
                    this._viewModel.RepeatState = MainViewModel.StateRepeat.ALL;
                    this._viewModel.RepeatSource = new BitmapImage(new Uri("../Ressources/repeat.png", UriKind.Relative));
                    break;
                case MainViewModel.StateRepeat.ALL:
                    this._viewModel.RepeatChecked = false;
                    this._viewModel.RepeatState = MainViewModel.StateRepeat.NONE;
                    break;
            }
        }

        public void PlayState()
        {
            this._viewModel.SourceImg = new BitmapImage(new Uri("../Ressources/pause.png", UriKind.Relative));
            this._viewModel.MediaPlayer.Play();
            MediaPlayerIsPlaying = true;
        }

        private void PauseState()
        {
            this._viewModel.SourceImg = new BitmapImage(new Uri("../Ressources/play.png", UriKind.Relative));
            this._viewModel.MediaPlayer.Pause();
            MediaPlayerIsPlaying = false;
        }
    }
}
