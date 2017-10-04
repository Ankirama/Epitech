using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace MyWindowsMediaPlayer.Model
{
    public class Filter
    {
        public MyWindowsMediaPlayer.ViewModel.MainViewModel.FormatMedia Format { get; set; }
        public string Name { get; set; }
        public string Path { get; set; }
    }
}
