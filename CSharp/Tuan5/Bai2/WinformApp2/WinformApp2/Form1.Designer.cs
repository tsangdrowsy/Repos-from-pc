namespace frmListbox
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
            this.lblTitle = new System.Windows.Forms.Label();
            this.grpListbox = new System.Windows.Forms.GroupBox();
            this.txtInput = new System.Windows.Forms.TextBox();
            this.btnNhap = new System.Windows.Forms.Button();
            this.lstBox = new System.Windows.Forms.ListBox();
            this.grpXuLy = new System.Windows.Forms.GroupBox();
            this.btnTong = new System.Windows.Forms.Button();
            this.btnXoaDauCuoi = new System.Windows.Forms.Button();
            this.btnXoaChon = new System.Windows.Forms.Button();
            this.btnTang2 = new System.Windows.Forms.Button();
            this.btnBinhPhuong = new System.Windows.Forms.Button();
            this.btnSoChan = new System.Windows.Forms.Button();
            this.btnSoLe = new System.Windows.Forms.Button();
            this.btnKetThuc = new System.Windows.Forms.Button();

            this.grpListbox.SuspendLayout();
            this.grpXuLy.SuspendLayout();
            this.SuspendLayout();

            // ===== lblTitle =====
            this.lblTitle.AutoSize = false;
            this.lblTitle.Font = new System.Drawing.Font("Arial", 20F, System.Drawing.FontStyle.Bold);
            this.lblTitle.ForeColor = System.Drawing.Color.OrangeRed;
            this.lblTitle.Location = new System.Drawing.Point(100, 10);
            this.lblTitle.Size = new System.Drawing.Size(400, 40);
            this.lblTitle.Text = "LISTBOX";
            this.lblTitle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;

            // ===== GroupBox: Listbox =====
            this.grpListbox.Controls.Add(this.txtInput);
            this.grpListbox.Controls.Add(this.btnNhap);
            this.grpListbox.Controls.Add(this.lstBox);
            this.grpListbox.Location = new System.Drawing.Point(12, 60);
            this.grpListbox.Size = new System.Drawing.Size(220, 310);
            this.grpListbox.Text = "Listbox";

            // txtInput
            this.txtInput.Location = new System.Drawing.Point(15, 25);
            this.txtInput.Size = new System.Drawing.Size(185, 20);

            // btnNhap
            this.btnNhap.Location = new System.Drawing.Point(15, 55);
            this.btnNhap.Size = new System.Drawing.Size(185, 30);
            this.btnNhap.Text = "Nhập";
            this.btnNhap.UseVisualStyleBackColor = true;

            // lstBox
            this.lstBox.Location = new System.Drawing.Point(15, 95);
            this.lstBox.Size = new System.Drawing.Size(185, 199);
            this.lstBox.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;

            // ===== GroupBox: Xử lý Listbox =====
            this.grpXuLy.Controls.Add(this.btnTong);
            this.grpXuLy.Controls.Add(this.btnXoaDauCuoi);
            this.grpXuLy.Controls.Add(this.btnXoaChon);
            this.grpXuLy.Controls.Add(this.btnTang2);
            this.grpXuLy.Controls.Add(this.btnBinhPhuong);
            this.grpXuLy.Controls.Add(this.btnSoChan);
            this.grpXuLy.Controls.Add(this.btnSoLe);
            this.grpXuLy.Location = new System.Drawing.Point(245, 60);
            this.grpXuLy.Size = new System.Drawing.Size(260, 310);
            this.grpXuLy.Text = "Xử lý Listbox";

            int btnY = 25;
            int btnH = 32;
            int btnGap = 8;

            this.btnTong.Location = new System.Drawing.Point(15, btnY);
            this.btnTong.Size = new System.Drawing.Size(230, btnH);
            this.btnTong.Text = "Tổng các phần tử trong List";
            this.btnTong.UseVisualStyleBackColor = true;
            btnY += btnH + btnGap;

            this.btnXoaDauCuoi.Location = new System.Drawing.Point(15, btnY);
            this.btnXoaDauCuoi.Size = new System.Drawing.Size(230, btnH);
            this.btnXoaDauCuoi.Text = "Xóa Phần tử đầu và cuối";
            this.btnXoaDauCuoi.UseVisualStyleBackColor = true;
            btnY += btnH + btnGap;

            this.btnXoaChon.Location = new System.Drawing.Point(15, btnY);
            this.btnXoaChon.Size = new System.Drawing.Size(230, btnH);
            this.btnXoaChon.Text = "Xóa Phần tử đang chọn";
            this.btnXoaChon.UseVisualStyleBackColor = true;
            btnY += btnH + btnGap;

            this.btnTang2.Location = new System.Drawing.Point(15, btnY);
            this.btnTang2.Size = new System.Drawing.Size(230, btnH);
            this.btnTang2.Text = "Tăng mỗi phần tử lên 2";
            this.btnTang2.UseVisualStyleBackColor = true;
            btnY += btnH + btnGap;

            this.btnBinhPhuong.Location = new System.Drawing.Point(15, btnY);
            this.btnBinhPhuong.Size = new System.Drawing.Size(230, btnH);
            this.btnBinhPhuong.Text = "Thay bằng bình phương";
            this.btnBinhPhuong.UseVisualStyleBackColor = true;
            btnY += btnH + btnGap;

            this.btnSoChan.Location = new System.Drawing.Point(15, btnY);
            this.btnSoChan.Size = new System.Drawing.Size(230, btnH);
            this.btnSoChan.Text = "Chọn số chẵn";
            this.btnSoChan.UseVisualStyleBackColor = true;
            btnY += btnH + btnGap;

            this.btnSoLe.Location = new System.Drawing.Point(15, btnY);
            this.btnSoLe.Size = new System.Drawing.Size(230, btnH);
            this.btnSoLe.Text = "Chọn số lẻ";
            this.btnSoLe.UseVisualStyleBackColor = true;

            // ===== btnKetThuc =====
            this.btnKetThuc.Location = new System.Drawing.Point(12, 380);
            this.btnKetThuc.Size = new System.Drawing.Size(493, 35);
            this.btnKetThuc.Text = "KẾT THÚC";
            this.btnKetThuc.UseVisualStyleBackColor = true;

            // ===== Form1 =====
            this.ClientSize = new System.Drawing.Size(520, 430);
            this.Controls.Add(this.lblTitle);
            this.Controls.Add(this.grpListbox);
            this.Controls.Add(this.grpXuLy);
            this.Controls.Add(this.btnKetThuc);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "frmListbox";

            this.grpListbox.ResumeLayout(false);
            this.grpListbox.PerformLayout();
            this.grpXuLy.ResumeLayout(false);
            this.ResumeLayout(false);
        }

        #endregion

        private System.Windows.Forms.Label lblTitle;
        private System.Windows.Forms.GroupBox grpListbox;
        private System.Windows.Forms.TextBox txtInput;
        private System.Windows.Forms.Button btnNhap;
        private System.Windows.Forms.ListBox lstBox;
        private System.Windows.Forms.GroupBox grpXuLy;
        private System.Windows.Forms.Button btnTong;
        private System.Windows.Forms.Button btnXoaDauCuoi;
        private System.Windows.Forms.Button btnXoaChon;
        private System.Windows.Forms.Button btnTang2;
        private System.Windows.Forms.Button btnBinhPhuong;
        private System.Windows.Forms.Button btnSoChan;
        private System.Windows.Forms.Button btnSoLe;
        private System.Windows.Forms.Button btnKetThuc;
    }
}