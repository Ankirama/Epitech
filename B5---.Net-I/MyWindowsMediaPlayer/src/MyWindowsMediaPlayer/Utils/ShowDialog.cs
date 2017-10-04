using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MahApps.Metro.Controls;
using MahApps.Metro.Controls.Dialogs;
using MyWindowsMediaPlayer.ViewModel;

namespace MyWindowsMediaPlayer.Utils
{
    public class ShowDialog
    {
        private readonly MainViewModel _mainView;

        public ShowDialog(ref MainViewModel mainViewModel)
        {
            this._mainView = mainViewModel;
        }

        public async Task<ProgressDialogController> ShowMessage(string title, string message, MessageDialogStyle style)
        {
            var metroWindow = (System.Windows.Application.Current.MainWindow as MetroWindow);
            if (metroWindow != null)
            {
                metroWindow.MetroDialogOptions.ColorScheme = MetroDialogColorScheme.Accented;
                return await metroWindow.ShowProgressAsync(title, message);
            }
            return null;
        }

        public async void ErrorMetroWindow(string message, ProgressDialogController controller = null)
        {
            if (controller != null)
                await Task.Run(() =>
                {
                    if (controller.IsOpen)
                        controller.CloseAsync();
                    while (controller.IsOpen) { };
                });
            var metroWindow = (System.Windows.Application.Current.MainWindow as MetroWindow);
            if (metroWindow != null)
            {
                metroWindow.MetroDialogOptions.ColorScheme = MetroDialogColorScheme.Inverted;
                await metroWindow.ShowMessageAsync("Error", message);
            }
        }

        public async Task<string> ShowInputDialog(string title, string message)
        {
            var metroWindow = (System.Windows.Application.Current.MainWindow as MetroWindow);
            if (metroWindow != null)
            {
                metroWindow.MetroDialogOptions.ColorScheme = MetroDialogColorScheme.Accented;
                //Console.WriteLine(input);
                return await metroWindow.ShowInputAsync(title, message);
            }
            return null;
        }
    }
}
