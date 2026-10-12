namespace DongHo
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
                components.Dispose();
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            this.lblTime = new System.Windows.Forms.Label();
            this.btnStart = new System.Windows.Forms.Button();
            this.timer1 = new System.Windows.Forms.Timer();
            this.SuspendLayout();

            // lblTime
            this.lblTime.AutoSize = false;
            this.lblTime.Font = new System.Drawing.Font("Consolas", 28F, System.Drawing.FontStyle.Bold);
            this.lblTime.Location = new System.Drawing.Point(30, 15);
            this.lblTime.Size = new System.Drawing.Size(200, 50);
            this.lblTime.Text = "30:00";
            this.lblTime.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;

            // btnStart
            this.btnStart.Location = new System.Drawing.Point(90, 75);
            this.btnStart.Size = new System.Drawing.Size(80, 30);
            this.btnStart.Text = "Bắt đầu";
            this.btnStart.UseVisualStyleBackColor = true;

            // timer1
            this.timer1.Interval = 1000; // 1 giây

            // Form1
            this.ClientSize = new System.Drawing.Size(260, 130);
            this.Controls.Add(this.lblTime);
            this.Controls.Add(this.btnStart);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Đồng hồ";

            this.ResumeLayout(false);
        }

        #endregion

        private System.Windows.Forms.Label lblTime;
        private System.Windows.Forms.Button btnStart;
        private System.Windows.Forms.Timer timer1;
    }
}