using System;
using System.Collections.Generic;
using System.Drawing;
using System.Windows.Forms;

namespace TuDienAnhViet
{
    public class Form1 : Form  // ← PHẢI kế thừa Form
    {
        private TabControl tabControl1;
        private TabPage tabAnhViet;
        private TabPage tabVietAnh;
        private Label lblInput;
        private Label lblMeaning;
        private ComboBox cboWord;
        private ListBox lstWords;
        private TextBox txtMeaning;
        private Button btnExit;

        private Dictionary<string, string> dictAnhViet = new Dictionary<string, string>();
        private Dictionary<string, string> dictVietAnh = new Dictionary<string, string>();
        private bool isAnhVietTab = true;

        public Form1()
        {
            InitializeComponent();
            LoadData();
            LoadWordList();
        }

        private void InitializeComponent()
        {
            // ===== TabControl =====
            tabControl1 = new TabControl();
            tabAnhViet = new TabPage();
            tabVietAnh = new TabPage();

            // ===== Controls =====
            lblInput = new Label();
            lblMeaning = new Label();
            cboWord = new ComboBox();
            lstWords = new ListBox();
            txtMeaning = new TextBox();
            btnExit = new Button();

            // --- Tab Anh-Việt ---
            tabAnhViet.Text = "ANH - VIỆT";
            tabAnhViet.Controls.Add(lblInput);
            tabAnhViet.Controls.Add(lblMeaning);
            tabAnhViet.Controls.Add(cboWord);
            tabAnhViet.Controls.Add(lstWords);
            tabAnhViet.Controls.Add(txtMeaning);

            // --- Tab Việt-Anh ---
            tabVietAnh.Text = "VIỆT - ANH";

            tabControl1.Controls.Add(tabAnhViet);
            tabControl1.Controls.Add(tabVietAnh);
            tabControl1.Location = new Point(12, 12);
            tabControl1.Size = new Size(560, 420);
            tabControl1.SelectedIndexChanged += TabControl1_SelectedIndexChanged;

            // --- Label ---
            lblInput.AutoSize = true;
            lblInput.Location = new Point(15, 20);
            lblInput.Text = "Tiếng Anh";
            lblInput.Font = new Font("Microsoft Sans Serif", 9F, FontStyle.Bold);

            lblMeaning.AutoSize = true;
            lblMeaning.Location = new Point(290, 20);
            lblMeaning.Text = "Tiếng Việt";
            lblMeaning.Font = new Font("Microsoft Sans Serif", 9F, FontStyle.Bold);

            // --- ComboBox ---
            cboWord.Location = new Point(15, 45);
            cboWord.Size = new Size(250, 21);
            cboWord.DropDownStyle = ComboBoxStyle.DropDown;
            cboWord.TextChanged += CboWord_TextChanged;
            cboWord.KeyDown += CboWord_KeyDown;

            // --- ListBox ---
            lstWords.Location = new Point(15, 75);
            lstWords.Size = new Size(250, 310);
            lstWords.DoubleClick += LstWords_DoubleClick;

            // --- TextBox ---
            txtMeaning.Location = new Point(290, 45);
            txtMeaning.Size = new Size(250, 340);
            txtMeaning.Multiline = true;
            txtMeaning.ScrollBars = ScrollBars.Both;
            txtMeaning.ReadOnly = true;

            // --- Button Thoát ---
            btnExit.Location = new Point(460, 445);
            btnExit.Size = new Size(100, 30);
            btnExit.Text = "Thoát";
            btnExit.Click += BtnExit_Click;

            // --- Form ---
            this.ClientSize = new Size(584, 491);
            this.Controls.Add(tabControl1);
            this.Controls.Add(btnExit);
            this.FormBorderStyle = FormBorderStyle.FixedSingle;
            this.MaximizeBox = false;
            this.StartPosition = FormStartPosition.CenterScreen;
            this.Text = "TỪ ĐIỂN ANH VIỆT - VIỆT ANH";
        }

        private void LoadData()
        {
            dictAnhViet.Add("student", "Sinh viên, học sinh");
            dictAnhViet.Add("teacher", "Giáo viên");
            dictAnhViet.Add("worker", "Công nhân");
            dictAnhViet.Add("hat", "Mũ, nón");
            dictAnhViet.Add("head", "Đầu");
            dictAnhViet.Add("mouse", "Chuột");
            dictAnhViet.Add("cat", "Mèo");
            dictAnhViet.Add("dog", "Chó");
            dictAnhViet.Add("snake", "Rắn");
            dictAnhViet.Add("lumb", "Khúc gỗ");
            dictAnhViet.Add("loan", "Khoản vay");
            dictAnhViet.Add("frog", "Ếch");
            dictAnhViet.Add("sheep", "Cừu");

            dictVietAnh.Add("sinh viên", "student");
            dictVietAnh.Add("học sinh", "student");
            dictVietAnh.Add("giáo viên", "teacher");
            dictVietAnh.Add("công nhân", "worker");
            dictVietAnh.Add("mũ", "hat");
            dictVietAnh.Add("nón", "hat");
            dictVietAnh.Add("đầu", "head");
            dictVietAnh.Add("chuột", "mouse");
            dictVietAnh.Add("mèo", "cat");
            dictVietAnh.Add("chó", "dog");
            dictVietAnh.Add("rắn", "snake");
            dictVietAnh.Add("khoản vay", "loan");
            dictVietAnh.Add("ếch", "frog");
            dictVietAnh.Add("cừu", "sheep");
        }

        private void LoadWordList()
        {
            lstWords.Items.Clear();
            var currentDict = isAnhVietTab ? dictAnhViet : dictVietAnh;
            foreach (var key in currentDict.Keys)
                lstWords.Items.Add(key);
        }

        private void TabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            isAnhVietTab = (tabControl1.SelectedIndex == 0);
            lblInput.Text = isAnhVietTab ? "Tiếng Anh" : "Tiếng Việt";
            lblMeaning.Text = isAnhVietTab ? "Tiếng Việt" : "Tiếng Anh";
            cboWord.Text = "";
            txtMeaning.Text = "";
            LoadWordList();
        }

        private void CboWord_TextChanged(object sender, EventArgs e)
        {
            string input = cboWord.Text.Trim().ToLower();
            if (string.IsNullOrEmpty(input)) { LoadWordList(); return; }

            var currentDict = isAnhVietTab ? dictAnhViet : dictVietAnh;
            lstWords.Items.Clear();

            foreach (var key in currentDict.Keys)
                if (key.ToLower().StartsWith(input))
                    lstWords.Items.Add(key);

            string closest = FindClosestMatch(input, currentDict);
            if (closest != null && closest.ToLower() != input.ToLower())
            {
                cboWord.Text = closest;
                cboWord.SelectionStart = input.Length;
                cboWord.SelectionLength = cboWord.Text.Length - input.Length;
            }
        }

        private string FindClosestMatch(string input, Dictionary<string, string> dict)
        {
            string best = null;
            int bestScore = int.MaxValue;
            foreach (var key in dict.Keys)
            {
                if (key.ToLower().StartsWith(input.ToLower()))
                {
                    int score = key.Length - input.Length;
                    if (score < bestScore) { bestScore = score; best = key; }
                }
            }
            return best;
        }

        private void CboWord_KeyDown(object sender, KeyEventArgs e)
        {
            if (e.KeyCode == Keys.Enter) { e.SuppressKeyPress = true; ShowMeaning(); }
        }

        private void LstWords_DoubleClick(object sender, EventArgs e)
        {
            if (lstWords.SelectedItem != null)
            {
                cboWord.Text = lstWords.SelectedItem.ToString();
                ShowMeaning();
            }
        }

        private void ShowMeaning()
        {
            string word = cboWord.Text.Trim().ToLower();
            if (string.IsNullOrEmpty(word)) { txtMeaning.Text = ""; return; }

            var currentDict = isAnhVietTab ? dictAnhViet : dictVietAnh;
            if (currentDict.ContainsKey(word))
                txtMeaning.Text = currentDict[word];
            else
            {
                string closest = FindClosestMatch(word, currentDict);
                if (closest != null) { txtMeaning.Text = currentDict[closest]; cboWord.Text = closest; }
                else txtMeaning.Text = "Không tìm thấy từ này!";
            }
        }

        private void BtnExit_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Bạn có muốn thoát?", "Xác nhận",
                MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
                Application.Exit();
        }

        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.Run(new Form1());
        }
    }
}