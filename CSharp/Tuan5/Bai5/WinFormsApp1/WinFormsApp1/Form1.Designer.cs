namespace WinFormsApp1;

partial class Form1
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
        menuStrip1 = new MenuStrip();
        bai1ToolStripMenuItem = new ToolStripMenuItem();
        bai2ToolStripMenuItem = new ToolStripMenuItem();
        menuStrip1.SuspendLayout();
        SuspendLayout();

        // menuStrip1
        menuStrip1.Items.AddRange(new ToolStripItem[] { bai1ToolStripMenuItem, bai2ToolStripMenuItem });
        menuStrip1.Location = new Point(0, 0);
        menuStrip1.Name = "menuStrip1";
        menuStrip1.Size = new Size(700, 24);
        menuStrip1.TabIndex = 0;
        menuStrip1.Text = "menuStrip1";

        // bai1ToolStripMenuItem
        bai1ToolStripMenuItem.Name = "bai1ToolStripMenuItem";
        bai1ToolStripMenuItem.Size = new Size(45, 20);
        bai1ToolStripMenuItem.Text = "Bài 1";
        bai1ToolStripMenuItem.Click += Bai1ToolStripMenuItem_Click;

        // bai2ToolStripMenuItem
        bai2ToolStripMenuItem.Name = "bai2ToolStripMenuItem";
        bai2ToolStripMenuItem.Size = new Size(45, 20);
        bai2ToolStripMenuItem.Text = "Bài 2";
        bai2ToolStripMenuItem.Click += Bai2ToolStripMenuItem_Click;

        // Form1
        AutoScaleDimensions = new SizeF(7F, 15F);
        AutoScaleMode = AutoScaleMode.Font;
        ClientSize = new Size(700, 500);
        Controls.Add(menuStrip1);
        IsMdiContainer = true;
        MainMenuStrip = menuStrip1;
        Name = "Form1";
        StartPosition = FormStartPosition.CenterScreen;
        Text = "BTVN_Tuan6";
        menuStrip1.ResumeLayout(false);
        menuStrip1.PerformLayout();
        ResumeLayout(false);
        PerformLayout();
    }

    private MenuStrip menuStrip1;
    private ToolStripMenuItem bai1ToolStripMenuItem;
    private ToolStripMenuItem bai2ToolStripMenuItem;
}