namespace C__.Net_XML_Serialize
{
    partial class MainForm
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.panel1 = new System.Windows.Forms.Panel();
            this.Add = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.AgeBox = new System.Windows.Forms.NumericUpDown();
            this.UserTB = new System.Windows.Forms.TextBox();
            this.SexBox = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.lvUsers = new System.Windows.Forms.ListView();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.deserialize = new System.Windows.Forms.Button();
            this.serialize = new System.Windows.Forms.Button();
            this.panel1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AgeBox)).BeginInit();
            this.SuspendLayout();
            // 
            // panel1
            // 
            this.panel1.Controls.Add(this.Add);
            this.panel1.Controls.Add(this.label3);
            this.panel1.Controls.Add(this.label2);
            this.panel1.Controls.Add(this.AgeBox);
            this.panel1.Controls.Add(this.UserTB);
            this.panel1.Controls.Add(this.SexBox);
            this.panel1.Controls.Add(this.label1);
            this.panel1.Location = new System.Drawing.Point(155, 33);
            this.panel1.Name = "panel1";
            this.panel1.Size = new System.Drawing.Size(280, 299);
            this.panel1.TabIndex = 0;
            // 
            // Add
            // 
            this.Add.Location = new System.Drawing.Point(145, 187);
            this.Add.Name = "Add";
            this.Add.Size = new System.Drawing.Size(102, 33);
            this.Add.TabIndex = 7;
            this.Add.Text = "Add";
            this.Add.UseVisualStyleBackColor = true;
            this.Add.Click += new System.EventHandler(this.Add_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(15, 145);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(26, 13);
            this.label3.TabIndex = 5;
            this.label3.Text = "Age";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(15, 88);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(25, 13);
            this.label2.TabIndex = 4;
            this.label2.Text = "Sex";
            // 
            // AgeBox
            // 
            this.AgeBox.Location = new System.Drawing.Point(18, 161);
            this.AgeBox.Name = "AgeBox";
            this.AgeBox.Size = new System.Drawing.Size(202, 20);
            this.AgeBox.TabIndex = 3;
            // 
            // UserTB
            // 
            this.UserTB.Location = new System.Drawing.Point(18, 49);
            this.UserTB.Name = "UserTB";
            this.UserTB.Size = new System.Drawing.Size(202, 20);
            this.UserTB.TabIndex = 2;
            // 
            // SexBox
            // 
            this.SexBox.FormattingEnabled = true;
            this.SexBox.Items.AddRange(new object[] {
            "-- Choose Sex --",
            "Male",
            "Female"});
            this.SexBox.Location = new System.Drawing.Point(18, 104);
            this.SexBox.Name = "SexBox";
            this.SexBox.Size = new System.Drawing.Size(202, 21);
            this.SexBox.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(15, 33);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 13);
            this.label1.TabIndex = 0;
            this.label1.Text = "Username";
            // 
            // lvUsers
            // 
            this.lvUsers.HideSelection = false;
            this.lvUsers.Location = new System.Drawing.Point(12, 33);
            this.lvUsers.Name = "lvUsers";
            this.lvUsers.Size = new System.Drawing.Size(137, 344);
            this.lvUsers.TabIndex = 1;
            this.lvUsers.UseCompatibleStateImageBehavior = false;
            this.lvUsers.View = System.Windows.Forms.View.List;
            this.lvUsers.SelectedIndexChanged += new System.EventHandler(this.lvUsers_SelectedIndexChanged);
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(31, 12);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(100, 20);
            this.textBox1.TabIndex = 2;
            this.textBox1.Text = "Users";
            this.textBox1.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(198, 12);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(189, 20);
            this.textBox2.TabIndex = 4;
            this.textBox2.Text = "Information";
            this.textBox2.TextAlign = System.Windows.Forms.HorizontalAlignment.Center;
            // 
            // deserialize
            // 
            this.deserialize.Location = new System.Drawing.Point(218, 338);
            this.deserialize.Name = "deserialize";
            this.deserialize.Size = new System.Drawing.Size(102, 33);
            this.deserialize.TabIndex = 5;
            this.deserialize.Text = "Deserialize";
            this.deserialize.UseVisualStyleBackColor = true;
            this.deserialize.Click += new System.EventHandler(this.deserialize_Click);
            // 
            // serialize
            // 
            this.serialize.Location = new System.Drawing.Point(326, 338);
            this.serialize.Name = "serialize";
            this.serialize.Size = new System.Drawing.Size(102, 33);
            this.serialize.TabIndex = 6;
            this.serialize.Text = "Serialize";
            this.serialize.UseVisualStyleBackColor = true;
            this.serialize.Click += new System.EventHandler(this.serialize_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(453, 383);
            this.Controls.Add(this.serialize);
            this.Controls.Add(this.deserialize);
            this.Controls.Add(this.textBox2);
            this.Controls.Add(this.textBox1);
            this.Controls.Add(this.lvUsers);
            this.Controls.Add(this.panel1);
            this.Name = "MainForm";
            this.Text = "MainForm";
            this.panel1.ResumeLayout(false);
            this.panel1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.AgeBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Panel panel1;
        private System.Windows.Forms.ListView lvUsers;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.TextBox UserTB;
        private System.Windows.Forms.ComboBox SexBox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.NumericUpDown AgeBox;
        private System.Windows.Forms.Button Add;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Button deserialize;
        private System.Windows.Forms.Button serialize;
    }
}

