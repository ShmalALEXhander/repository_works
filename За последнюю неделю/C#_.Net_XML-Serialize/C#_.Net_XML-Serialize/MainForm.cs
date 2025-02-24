using System;
using System.Windows.Forms;
using System.IO;
using System.Xml.Serialization;

namespace C__.Net_XML_Serialize
{
    public partial class MainForm : Form
    {
        public MainForm()
        {
            InitializeComponent();
            ClearInput();
        }
        public void ClearInput()
        {// для инициализации полей (полезно для MainForm)
            UserTB.Text = string.Empty;
            SexBox.SelectedIndex = 0;
            AgeBox.Value = 0;
        }
        private void Add_Click(object sender, EventArgs e)
        {
            User user = new User(UserTB.Text, SexBox.SelectedIndex, (int)AgeBox.Value);
            Addv(user);
            ClearInput();
        }
        private void lvUsers_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (lvUsers.SelectedItems.Count == 1)
            {
                User user = (User)lvUsers.SelectedItems[0].Tag;
                if (lvUsers.SelectedItems.Count == 1)
                {
                    UserTB.Text = user.UserName;
                    SexBox.SelectedIndex = user.Sex;
                    AgeBox.Value = user.Age;
                }
                else if (lvUsers.SelectedItems.Count == 0)
                    ClearInput();
            }
        }
        private Users DeserializeXML()
        {
            XmlSerializer xml = new XmlSerializer(typeof(Users));
            using (FileStream fs = new FileStream("Users.xml", FileMode.OpenOrCreate))
            {
                Users users = (Users)xml.Deserialize(fs);
                return users;
            }
        }
        private void SerializeXML(Users users)
        {
            XmlSerializer xml = new XmlSerializer(typeof(Users));
            using (FileStream fs = new FileStream("Users.xml", FileMode.OpenOrCreate))
                xml.Serialize(fs, users);
        }
        private void serialize_Click(object sender, EventArgs e)
        {
            Users users = new Users();
            foreach (ListViewItem item in lvUsers.Items)
                if (item.Tag != null)
                    users.UsersList.Add((User)item.Tag);
            SerializeXML(users);
        }   
        private void deserialize_Click(object sender, EventArgs e)
        {
            ClearInput();
            Users users = DeserializeXML();
            foreach (User user in users.UsersList)
                Addv(user);
        }
        private void Addv(User user)
        {
            ListViewItem LVI = new ListViewItem(user.UserName);
            LVI.Tag = user;
            lvUsers.Items.Add(LVI);// визуализатор вроде бы
        }
    }//Структура главное - правильно её воспользуйся 
}
