using System;
using System.Windows.Forms;

namespace DongHo
{
    public partial class Form1 : Form
    {
        private int totalSeconds = 30 * 60; // 30 phút = 1800 giây
        private bool isRunning = false;

        public Form1()
        {
            InitializeComponent();
            btnStart.Click += BtnStart_Click;
            timer1.Tick += Timer1_Tick;
        }

        private void BtnStart_Click(object sender, EventArgs e)
        {
            if (!isRunning)
            {
                isRunning = true;
                timer1.Start();
                btnStart.Text = "Dừng";
            }
            else
            {
                isRunning = false;
                timer1.Stop();
                btnStart.Text = "Bắt đầu";
            }
        }

        private void Timer1_Tick(object sender, EventArgs e)
        {
            totalSeconds--;

            if (totalSeconds <= 0)
            {
                totalSeconds = 0;
                timer1.Stop();
                isRunning = false;
                btnStart.Text = "Bắt đầu";
                MessageBox.Show("Hết giờ!", "Thông báo",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

            int minutes = totalSeconds / 60;
            int seconds = totalSeconds % 60;
            lblTime.Text = $"{minutes:D2}:{seconds:D2}";
        }
    }
}