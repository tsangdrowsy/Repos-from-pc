namespace BTVN_Tuan6
{
    partial class frmBaitap2
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
            this.lblMessage = new System.Windows.Forms.Label();
            this.SuspendLayout();

            this.lblMessage.AutoSize = true;
            this.lblMessage.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F);
            this.lblMessage.Location = new System.Drawing.Point(100, 80);
            this.lblMessage.Text = "Đây là Form Bài 2";

            this.ClientSize = new System.Drawing.Size(400, 250);
            this.Controls.Add(this.lblMessage);
            this.Name = "frmBaitap2";
            this.Text = "frmBaitap2";

            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion

        private System.Windows.Forms.Label lblMessage;
    }
}