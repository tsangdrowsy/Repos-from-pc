using System;
using System.Windows.Forms;

namespace frmListbox
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            // Gán sự kiện
            btnNhap.Click += BtnNhap_Click;
            btnTong.Click += BtnTong_Click;
            btnXoaDauCuoi.Click += BtnXoaDauCuoi_Click;
            btnXoaChon.Click += BtnXoaChon_Click;
            btnTang2.Click += BtnTang2_Click;
            btnBinhPhuong.Click += BtnBinhPhuong_Click;
            btnSoChan.Click += BtnSoChan_Click;
            btnSoLe.Click += BtnSoLe_Click;
            btnKetThuc.Click += BtnKetThuc_Click;
        }

        // ===== 1. Nhập phần tử vào ListBox =====
        private void BtnNhap_Click(object sender, EventArgs e)
        {
            if (int.TryParse(txtInput.Text.Trim(), out int number))
            {
                lstBox.Items.Add(number);
                txtInput.Clear();
                txtInput.Focus();
            }
            else
            {
                MessageBox.Show("Vui lòng nhập số nguyên hợp lệ!", "Lỗi",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
            }
        }

        // ===== 2. Tính tổng các phần tử =====
        private void BtnTong_Click(object sender, EventArgs e)
        {
            if (lstBox.Items.Count == 0)
            {
                MessageBox.Show("ListBox đang trống!", "Thông báo",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }

            int tong = 0;
            foreach (var item in lstBox.Items)
            {
                tong += Convert.ToInt32(item);
            }

            MessageBox.Show($"Tổng các phần tử trong List = {tong}",
                "Kết quả", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        // ===== 3. Xóa phần tử đầu và cuối =====
        private void BtnXoaDauCuoi_Click(object sender, EventArgs e)
        {
            if (lstBox.Items.Count == 0)
            {
                MessageBox.Show("ListBox đang trống!", "Thông báo",
                    MessageBoxButtons.OK, MessageBoxIcon.Information);
                return;
            }

            // Xóa cuối trước, rồi xóa đầu (để index không bị lệch)
            lstBox.Items.RemoveAt(lstBox.Items.Count - 1);

            if (lstBox.Items.Count > 0)
                lstBox.Items.RemoveAt(0);
        }

        // ===== 4. Xóa phần tử đang chọn =====
        private void BtnXoaChon_Click(object sender, EventArgs e)
        {
            if (lstBox.SelectedItems.Count == 0)
            {
                MessageBox.Show("Chưa chọn phần tử nào!", "Thông báo",
                    MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }

            // Xóa từ dưới lên để index không bị lệch
            for (int i = lstBox.SelectedItems.Count - 1; i >= 0; i--)
            {
                lstBox.Items.Remove(lstBox.SelectedItems[i]);
            }
        }

        // ===== 5. Tăng mỗi phần tử lên 2 =====
        private void BtnTang2_Click(object sender, EventArgs e)
        {
            if (lstBox.Items.Count == 0) return;

            for (int i = 0; i < lstBox.Items.Count; i++)
            {
                int val = Convert.ToInt32(lstBox.Items[i]);
                lstBox.Items[i] = val + 2;
            }
        }

        // ===== 6. Thay bằng bình phương =====
        private void BtnBinhPhuong_Click(object sender, EventArgs e)
        {
            if (lstBox.Items.Count == 0) return;

            for (int i = 0; i < lstBox.Items.Count; i++)
            {
                int val = Convert.ToInt32(lstBox.Items[i]);
                lstBox.Items[i] = val * val;
            }
        }

        // ===== 7. Chọn số chẵn =====
        private void BtnSoChan_Click(object sender, EventArgs e)
        {
            lstBox.ClearSelected();

            for (int i = 0; i < lstBox.Items.Count; i++)
            {
                int val = Convert.ToInt32(lstBox.Items[i]);
                if (val % 2 == 0)
                    lstBox.SetSelected(i, true);
            }
        }

        // ===== 8. Chọn số lẻ =====
        private void BtnSoLe_Click(object sender, EventArgs e)
        {
            lstBox.ClearSelected();

            for (int i = 0; i < lstBox.Items.Count; i++)
            {
                int val = Convert.ToInt32(lstBox.Items[i]);
                if (val % 2 != 0)
                    lstBox.SetSelected(i, true);
            }
        }

        // ===== 9. Kết thúc =====
        private void BtnKetThuc_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Bạn có muốn thoát?", "Xác nhận",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                Application.Exit();
            }
        }
    }
}