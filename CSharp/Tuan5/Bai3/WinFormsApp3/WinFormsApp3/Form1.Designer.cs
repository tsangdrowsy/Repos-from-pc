namespace frmBTVN2
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
            this.treeView1 = new System.Windows.Forms.TreeView();
            this.grpInput = new System.Windows.Forms.GroupBox();
            this.lblFirstName = new System.Windows.Forms.Label();
            this.lblLastName = new System.Windows.Forms.Label();
            this.txtFirstName = new System.Windows.Forms.TextBox();
            this.txtLastName = new System.Windows.Forms.TextBox();
            this.btnAdd = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();

            this.grpInput.SuspendLayout();
            this.SuspendLayout();

            // ===== TreeView =====
            this.treeView1.Location = new System.Drawing.Point(12, 12);
            this.treeView1.Size = new System.Drawing.Size(220, 420);
            this.treeView1.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F);

            // ===== GroupBox Input =====
            this.grpInput.Controls.Add(this.lblFirstName);
            this.grpInput.Controls.Add(this.lblLastName);
            this.grpInput.Controls.Add(this.txtFirstName);
            this.grpInput.Controls.Add(this.txtLastName);
            this.grpInput.Controls.Add(this.btnAdd);
            this.grpInput.Location = new System.Drawing.Point(245, 12);
            this.grpInput.Size = new System.Drawing.Size(280, 160);
            this.grpInput.Text = "";

            // lblFirstName
            this.lblFirstName.AutoSize = true;
            this.lblFirstName.Location = new System.Drawing.Point(15, 25);
            this.lblFirstName.Text = "First Name";
            this.lblFirstName.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F);

            // txtFirstName
            this.txtFirstName.Location = new System.Drawing.Point(110, 22);
            this.txtFirstName.Size = new System.Drawing.Size(150, 20);

            // lblLastName
            this.lblLastName.AutoSize = true;
            this.lblLastName.Location = new System.Drawing.Point(15, 60);
            this.lblLastName.Text = "Last Name";
            this.lblLastName.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F);

            // txtLastName
            this.txtLastName.Location = new System.Drawing.Point(110, 57);
            this.txtLastName.Size = new System.Drawing.Size(150, 20);

            // btnAdd
            this.btnAdd.Location = new System.Drawing.Point(185, 95);
            this.btnAdd.Size = new System.Drawing.Size(75, 30);
            this.btnAdd.Text = "Add";
            this.btnAdd.UseVisualStyleBackColor = true;

            // ===== btnExit =====
            this.btnExit.Location = new System.Drawing.Point(425, 395);
            this.btnExit.Size = new System.Drawing.Size(100, 35);
            this.btnExit.Text = "Exit";
            this.btnExit.UseVisualStyleBackColor = true;

            // ===== Form1 =====
            this.ClientSize = new System.Drawing.Size(540, 445);
            this.Controls.Add(this.treeView1);
            this.Controls.Add(this.grpInput);
            this.Controls.Add(this.btnExit);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "frmBTVN2";

            this.grpInput.ResumeLayout(false);
            this.grpInput.PerformLayout();
            this.ResumeLayout(false);
        }

        #endregion

        private System.Windows.Forms.TreeView treeView1;
        private System.Windows.Forms.GroupBox grpInput;
        private System.Windows.Forms.Label lblFirstName;
        private System.Windows.Forms.Label lblLastName;
        private System.Windows.Forms.TextBox txtFirstName;
        private System.Windows.Forms.TextBox txtLastName;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.Button btnExit;
    }
}