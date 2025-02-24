using System;
using System.Collections.Generic;

namespace C__.Net_XML_Serialize
{
    [Serializable]
    public class Users
    {
        public List<User> UsersList = new List<User>();
    }
    [Serializable]
    public class User
    {
        public string UserName;
        public int Sex;
        public int Age;
        public User() { }
        public User(string userName, int sex, int age)
        {
            UserName = userName;
            Sex = sex;
            Age = age;
        }
    }
}
