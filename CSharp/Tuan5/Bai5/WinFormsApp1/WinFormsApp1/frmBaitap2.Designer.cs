namespace WinFormsApp1;

partial class frmBaitap2
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
        lblMessage = new Label();
        SuspendLayout();

        lblMessage.AutoSize = true;
        lblMessage.Font = new Font("Microsoft Sans Serif", 14F);
        lblMessage.Location = new Point(100, 80);
        lblMessage.Text = "Đây là Form Bài 2";

        AutoScaleDimensions = new SizeF(7F, 15F);
        AutoScaleMode = AutoScaleMode.Font;
        ClientSize = new Size(400, 250);
        Controls.Add(lblMessage);
        Name = "frmBaitap2";
        Text = "frmBaitap2";
        ResumeLayout(false);
        PerformLayout();
    }

    private Label lblMessage;
}