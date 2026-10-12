using System;
using System.Windows.Forms;

namespace frmBTVN2
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            btnAdd.Click += BtnAdd_Click;
            btnExit.Click += BtnExit_Click;

            // Load TreeView khi form khởi tạo
            LoadTreeView();
        }

        // ===== Load tất cả ký tự A → Z vào TreeView =====
        private void LoadTreeView()
        {
            treeView1.Nodes.Clear();

            for (char c = 'A'; c <= 'Z'; c++)
            {
                TreeNode node = new TreeNode(c.ToString());
                treeView1.Nodes.Add(node);
            }

            // Mở rộng node đầu tiên để demo
            treeView1.ExpandAll();
        }

        // ===== Thêm người mới vào TreeView =====
        private void BtnAdd_Click(object sender, EventArgs e)
        {
            string firstName = txtFirstName.Text.Trim();
            string lastName = txtLastName.Text.Trim();

            // Kiểm tra dữ liệu nhập
            if (string.IsNullOrEmpty(firstName) || string.IsNullOrEmpty(lastName))
            {
                MessageBox.Show("Vui lòng nhập đầy đủ First Name và Last Name!",
                    "Lỗi", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            // Lấy chữ cái đầu của First Name (tên) và chuyển thành chữ hoa
            char firstChar = char.ToUpper(firstName[0]);

            // Kiểm tra có phải chữ cái A-Z không
            if (firstChar < 'A' || firstChar > 'Z')
            {
                MessageBox.Show("Chữ cái đầu của tên phải từ A đến Z!",
                    "Lỗi", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            // Tìm node tương ứng với chữ cái đầu
            TreeNode parentNode = null;
            foreach (TreeNode node in treeView1.Nodes)
            {
                if (node.Text.ToUpper() == firstChar.ToString())
                {
                    parentNode = node;
                    break;
                }
            }

            if (parentNode != null)
            {
                // Tạo node con: "FirstName, LastName"
                string displayName = $"{firstName}, {lastName}";
                TreeNode childNode = new TreeNode(displayName);
                parentNode.Nodes.Add(childNode);

                // Mở rộng node cha để hiển thị node con vừa thêm
                parentNode.Expand();

                // Chọn node vừa thêm
                treeView1.SelectedNode = childNode;

                // Xóa input sau khi thêm thành công
                txtFirstName.Clear();
                txtLastName.Clear();
                txtFirstName.Focus();
            }
        }

        // ===== Thoát chương trình =====
        private void BtnExit_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Bạn có muốn thoát?", "Xác nhận",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                Application.Exit();
            }
        }
    }
}