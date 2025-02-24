using MySql.Data.MySqlClient;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace BaseDateGraphicsInterfaceWindows
{
    public partial class RegisterForm : Form
    {
        public RegisterForm()
        {
            InitializeComponent();
            userName.Text = "Имя";
            userSurname.Text = "Фамилия";
            userLogin.Text = "Логин";
            userPassword.Text = "Пароль";
        }

        private void RegisterForm_Load(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void close_MouseClick(object sender, MouseEventArgs e)
        {
            Application.Exit();
        }

        private void close_MouseEnter(object sender, EventArgs e)
        {
            close.ForeColor = Color.Green;
        }

        private void close_MouseLeave(object sender, EventArgs e)
        {
            close.ForeColor = Color.Black;
        }
        Point lastPoint;
        private void label1_MouseMove(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                this.Left += e.X - lastPoint.X;
                this.Top += e.Y - lastPoint.Y;
            }
        }

        private void buttonRegister_Click(object sender, EventArgs e)
        {
            if (userName.Text == "Имя" || userName.Text == "" || userName.Text == " " ||
                userSurname.Text == "Фамилия" || userSurname.Text == "" || userSurname.Text == " " ||
                userLogin.Text == "Логин" || userLogin.Text == "" || userLogin.Text == " " ||
                userPassword.Text == "Пароль" || userPassword.Text == "" || userPassword.Text == " ")
            {
                MessageBox.Show("Некорректно заполнено 1 из полей");
                return;
            }
            if (isUserExists())
                return;

            DB db = new DB();
            MySqlCommand command = new MySqlCommand("INSERT INTO `users` (`login`, `pass`, `name`, `surname`) VALUES (@login, @pass,@name, @surname)", db.getConnection());

            command.Parameters.Add("@login", MySqlDbType.VarChar).Value = userLogin.Text;
            command.Parameters.Add("@pass", MySqlDbType.VarChar).Value = userPassword.Text;
            command.Parameters.Add("@name", MySqlDbType.VarChar).Value = userName.Text;
            command.Parameters.Add("@surname", MySqlDbType.VarChar).Value = userSurname.Text;

            db.openConnection();

            if (command.ExecuteNonQuery() == 1)
                MessageBox.Show("Аккаунт был создан");
            else
                MessageBox.Show("Аккаунт не был создан");

            db.closeConnection();

            this.Hide();
            LoginForm LoginForm = new LoginForm();
            LoginForm.Show();
        }

        private void TranspLoginer_MouseEnter(object sender, EventArgs e)
        {
            TranspLoginer.ForeColor = Color.Green;
        }

        private void TranspLoginer_MouseLeave(object sender, EventArgs e)
        {
            TranspLoginer.ForeColor = Color.Black;
        }

        private void TranspLoginer_Click(object sender, EventArgs e)
        {
            this.Hide();
            LoginForm LoginForm = new LoginForm();
            LoginForm.Show();
        }
        public Boolean isUserExists()
        {
            DB db = new DB(); //Просто набор объект предусмотренный пространством (имён)
            DataTable table = new DataTable();
            MySqlDataAdapter adapter = new MySqlDataAdapter();

            MySqlCommand command = new MySqlCommand("SELECT * FROM `users` WHERE `login` = @uL", db.getConnection());// Достаёт запрос из БД. Заглушка для повышения безопастности
            command.Parameters.Add("@uL", MySqlDbType.VarChar).Value = userLogin.Text; // Защита от SQl--инъекция, большая тема, это решение отчасти решает проблему с безопастностью.

            adapter.SelectCommand = command;
            adapter.Fill(table);

            if (table.Rows.Count > 0)
            {
                MessageBox.Show("Такой логин уже есть, введите другой");
                return true;
            }
            else return false;
        }
    }
}
