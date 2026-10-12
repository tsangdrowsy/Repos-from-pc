namespace WinFormsApp1;

partial class frmBaitap1
{
    private System.ComponentModel.IContainer components = null;

    protected override void Dispose(bool disposing)
    {
        if (disposing && (components != null))
            components.Dispose();
        base.Dispose(disposing);
    }

    private void InitializeComponent()
    {
        lblHoTen = new Label();
        lblMaSV = new Label();
        lblGioiTinh = new Label();
        lblNgoaiNgu = new Label();
        lblDanToc = new Label();
        txtHoTen = new TextBox();
        txtMaSV = new TextBox();
        radNam = new RadioButton();
        radNu = new RadioButton();
        chkAnh = new CheckBox();
        chkPhap = new CheckBox();
        chkHoa = new CheckBox();
        cboDanToc = new ComboBox();
        dgvData = new DataGridView();
        colHoTen = new DataGridViewTextBoxColumn();
        colMaSV = new DataGridViewTextBoxColumn();
        colGioiTinh = new DataGridViewTextBoxColumn();
        colNgoaiNgu = new DataGridViewTextBoxColumn();
        colDanToc = new DataGridViewTextBoxColumn();
        ((System.ComponentModel.ISupportInitialize)dgvData).BeginInit();
        SuspendLayout();

        int labelX = 30, inputX = 160;
        int startY = 20, gap = 40;

        lblHoTen.AutoSize = false;
        lblHoTen.Location = new Point(labelX, startY);
        lblHoTen.Size = new Size(120, 20);
        lblHoTen.Text = "Họ và Tên";
        lblHoTen.TextAlign = ContentAlignment.MiddleLeft;

        lblMaSV.AutoSize = false;
        lblMaSV.Location = new Point(labelX, startY + gap);
        lblMaSV.Size = new Size(120, 20);
        lblMaSV.Text = "Mã sinh viên";
        lblMaSV.TextAlign = ContentAlignment.MiddleLeft;

        lblGioiTinh.AutoSize = false;
        lblGioiTinh.Location = new Point(labelX, startY + gap * 2);
        lblGioiTinh.Size = new Size(120, 20);
        lblGioiTinh.Text = "Giới tính";
        lblGioiTinh.TextAlign = ContentAlignment.MiddleLeft;

        lblNgoaiNgu.AutoSize = false;
        lblNgoaiNgu.Location = new Point(labelX, startY + gap * 3);
        lblNgoaiNgu.Size = new Size(120, 20);
        lblNgoaiNgu.Text = "Ngoại ngữ";
        lblNgoaiNgu.TextAlign = ContentAlignment.MiddleLeft;

        lblDanToc.AutoSize = false;
        lblDanToc.Location = new Point(labelX, startY + gap * 4);
        lblDanToc.Size = new Size(120, 20);
        lblDanToc.Text = "Dân tộc";
        lblDanToc.TextAlign = ContentAlignment.MiddleLeft;

        txtHoTen.Location = new Point(inputX, startY);
        txtHoTen.Size = new Size(250, 23);

        txtMaSV.Location = new Point(inputX, startY + gap);
        txtMaSV.Size = new Size(250, 23);

        radNam.AutoSize = true;
        radNam.Location = new Point(inputX, startY + gap * 2 + 3);
        radNam.Text = "Nam";
        radNam.Checked = true;

        radNu.AutoSize = true;
        radNu.Location = new Point(inputX + 80, startY + gap * 2 + 3);
        radNu.Text = "Nữ";

        chkAnh.AutoSize = true;
        chkAnh.Location = new Point(inputX, startY + gap * 3 + 3);
        chkAnh.Text = "Anh";

        chkPhap.AutoSize = true;
        chkPhap.Location = new Point(inputX + 70, startY + gap * 3 + 3);
        chkPhap.Text = "Pháp";

        chkHoa.AutoSize = true;
        chkHoa.Location = new Point(inputX + 140, startY + gap * 3 + 3);
        chkHoa.Text = "Hoa";

        cboDanToc.Location = new Point(inputX, startY + gap * 4);
        cboDanToc.Size = new Size(150, 23);
        cboDanToc.DropDownStyle = ComboBoxStyle.DropDownList;
        cboDanToc.Items.AddRange(new object[] { "Kinh", "Tày", "Thái", "Mường", "Hoa", "Khmer", "Nùng", "Mông" });
        cboDanToc.SelectedIndex = 0;

        dgvData.Columns.AddRange(new DataGridViewColumn[] { colHoTen, colMaSV, colGioiTinh, colNgoaiNgu, colDanToc });
        dgvData.Location = new Point(12, 230);
        dgvData.Size = new Size(560, 200);
        dgvData.AllowUserToAddRows = false;
        dgvData.ReadOnly = true;

        colHoTen.HeaderText = "Họ tên";
        colHoTen.Width = 130;
        colMaSV.HeaderText = "Mã sinh viên";
        colMaSV.Width = 100;
        colGioiTinh.HeaderText = "Giới tính";
        colGioiTinh.Width = 80;
        colNgoaiNgu.HeaderText = "Ngoại ngữ";
        colNgoaiNgu.Width = 120;
        colDanToc.HeaderText = "Dân tộc";
        colDanToc.Width = 100;

        AutoScaleDimensions = new SizeF(7F, 15F);
        AutoScaleMode = AutoScaleMode.Font;
        ClientSize = new Size(584, 441);
        Controls.Add(lblHoTen);
        Controls.Add(lblMaSV);
        Controls.Add(lblGioiTinh);
        Controls.Add(lblNgoaiNgu);
        Controls.Add(lblDanToc);
        Controls.Add(txtHoTen);
        Controls.Add(txtMaSV);
        Controls.Add(radNam);
        Controls.Add(radNu);
        Controls.Add(chkAnh);
        Controls.Add(chkPhap);
        Controls.Add(chkHoa);
        Controls.Add(cboDanToc);
        Controls.Add(dgvData);
        Name = "frmBaitap1";
        Text = "frmBaitap1";
        ((System.ComponentModel.ISupportInitialize)dgvData).EndInit();
        ResumeLayout(false);
        PerformLayout();
    }

    private Label lblHoTen;
    private Label lblMaSV;
    private Label lblGioiTinh;
    private Label lblNgoaiNgu;
    private Label lblDanToc;
    private TextBox txtHoTen;
    private TextBox txtMaSV;
    private RadioButton radNam;
    private RadioButton radNu;
    private CheckBox chkAnh;
    private CheckBox chkPhap;
    private CheckBox chkHoa;
    private ComboBox cboDanToc;
    private DataGridView dgvData;
    private DataGridViewTextBoxColumn colHoTen;
    private DataGridViewTextBoxColumn colMaSV;
    private DataGridViewTextBoxColumn colGioiTinh;
    private DataGridViewTextBoxColumn colNgoaiNgu;
    private DataGridViewTextBoxColumn colDanToc;
}