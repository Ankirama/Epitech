using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace MyWindowsMediaPlayer.Model
{
    public class MusicDB
    {
        public string ID { get; set; }
        public ImageSource Musique { get; set; }
        public string NameMusique { get; set; }
        public string Artiste { get; set; }
        public string Duration { get; set; }
        public string Album { get; set; }
        public string Path { get; set; }
    }
}
