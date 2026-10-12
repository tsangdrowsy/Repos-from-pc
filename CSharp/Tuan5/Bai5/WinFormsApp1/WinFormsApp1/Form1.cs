

namespace WinFormsApp1;

public partial class Form1 : Form
{
    public Form1()
    {
        InitializeComponent();
    }

    private void Bai1ToolStripMenuItem_Click(object? sender, EventArgs e)
    {
        frmBaitap1 f = new frmBaitap1();
        f.MdiParent = this;
        f.Show();
    }

    private void Bai2ToolStripMenuItem_Click(object? sender, EventArgs e)
    {
        frmBaitap2 f = new frmBaitap2();
        f.MdiParent = this;
        f.Show();
    }
}