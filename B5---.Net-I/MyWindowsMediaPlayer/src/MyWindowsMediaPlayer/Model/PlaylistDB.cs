using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections.ObjectModel;

namespace MyWindowsMediaPlayer.Model
{
    public class PlaylistDB
    {
        public int ID { get; set; }
        public string NamePlaylist { get; set; }
        public ObservableCollection<MusicDB> MusicsList { get; set; }
    }
}
