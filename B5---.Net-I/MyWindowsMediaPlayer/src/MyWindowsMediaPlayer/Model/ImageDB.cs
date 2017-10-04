using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media;

namespace MyWindowsMediaPlayer.Model
{
    public class ImageDB
    {
        public string ID { get; set; }
        public string NameImage { get; set; }
        public string Album { get; set; }
        public string Path { get; set; }
        public ImageSource SourceImage { get; set; }
    }
}
