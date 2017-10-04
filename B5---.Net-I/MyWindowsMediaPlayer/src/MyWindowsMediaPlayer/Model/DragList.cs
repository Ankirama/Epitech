using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MyWindowsMediaPlayer.ViewModel;

namespace MyWindowsMediaPlayer.Model
{
    public class DragList
    {
        public string Name { get; set; }
        public string Path { get; set; }
        public MainViewModel.FormatMedia type { get; set; }
    }
}
