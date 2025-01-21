using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace DotNetLaba7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Type t = typeof(MyClass);
            Console.WriteLine("Поддерживаемые методы: ");
            foreach (MethodInfo m in t.GetMethods())
            {
                // Отображаем тип результата и имя метода
                Console.WriteLine(" {0} {1}(…)", m.ReturnType.Name,
                m.Name);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            MyTestClass.getStrMethod(typeof(MyClass));
        }

        private async void button3_Click(object sender, EventArgs e)
        {
            string path = "C:\\Users\\Александр\\Desktop\\INPUT1.txt";

            using (StreamReader reader = new StreamReader(path))
            {
                string line;
                while ((line = await reader.ReadLineAsync()) != null)
                {
                    string[] words = line.Split(' ');
                    MyTestClass.RunMethod("DotNetLaba7.AnotherTestClass", "printSum", words[0], words[1]);
                }

            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            var obj = new MyClass();
        DebugPrinter.PrintObject(obj);
        }

        private void button5_Click(object sender, EventArgs e)
        {
            int bum = 5;
            DopClass a1 = new DopClass(bum);
            a1.AddElem(5);
            a1.Multip(5);
            textBox1.Text = Convert.ToString(a1.a);
        }
    }
}
