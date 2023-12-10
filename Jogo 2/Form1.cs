using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Jogo_2
{
    public partial class Form1 : Form
    {
        int SpeedPly; // PLAYER SPEED 

        PictureBox[] Drops; //INITATE THE FALLING OBJECTS 
        int DropsSpeed; // FALLING OBJECTS SPEED

        int dir = 0; // direction of the ship



        public Form1()
        {
            InitializeComponent();
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            if (Player.Right < 580)
            {
                Player.Left += SpeedPly;
            }
            if (dir == 0)
            {
                Player.Image.RotateFlip(RotateFlipType.RotateNoneFlipX);
                dir++;
            }

 
        }

        private void MoveLeft_Tick(object sender, EventArgs e)
        {
            if (Player.Left > 10)
            {
                Player.Left -= SpeedPly;
            }
            if (dir == 1)
            {
                Player.Image.RotateFlip(RotateFlipType.RotateNoneFlipX);
                dir--;
            }


        }

        private void Form1_Load(object sender, EventArgs e)
        {
            SpeedPly = 4; // SPEED IN PIXELS PER TIMER INTERVAL
            DropsSpeed = 8; // SPEED IN PIXELS PER TIMER INTERVAL

            //Load Images for drops heroes
            Image luffy = Image.FromFile(@"img1\\luffy.png");
            Image nami = Image.FromFile(@"img1\\nami.png");
            Image zoro = Image.FromFile(@"img1\\zoro.png");
            Image sanji = Image.FromFile(@"img1\\sanji.png");
            Image chooper = Image.FromFile(@"img1\\chooper.png");
            Image brook = Image.FromFile(@"img1\\brook.png");
            Image usspo = Image.FromFile(@"img1\\usspo.png");
            Image robin = Image.FromFile(@"img1\\robin.png");

            //Load Images for drops Enemies

            Image snake = Image.FromFile(@"img1\\snake.png");
            Image kraken = Image.FromFile(@"img1\\kraken.png");

            Drops = new PictureBox[10];

            //INITATE Drops PICTURE BOX
            for (int i = 0 ; i<Drops.Length ; i++)
            {
                Drops[i] = new PictureBox();
                Drops[i].Size = new Size(100, 150);
                Drops[i].SizeMode = PictureBoxSizeMode.Zoom;
                Drops[i].BorderStyle = BorderStyle.None;
                Drops[i].Visible = false;
                this.Controls.Add(Drops[i]);
                Drops[i].Location = new Point((i + 1) * 100, -50);

            }

            Drops[0].Image = luffy;
            Drops[1].Image = sanji;
            Drops[2].Image = zoro;
            Drops[3].Image = nami;
            Drops[4].Image = brook;
            Drops[5].Image = chooper;
            Drops[6].Image = usspo;
            Drops[7].Image = robin;

            Drops[8].Image = kraken;
            Drops[9].Image = snake;

        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            if(e.KeyCode == Keys.Right)
            {
                MoveRight.Start();
                
            }
            if (e.KeyCode == Keys.Left)
            {
                MoveLeft.Start();
                
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            MoveLeft.Stop();
            MoveRight.Stop();
        }

        private void DropTimer_Tick(object sender, EventArgs e)
        {
            DropObjects(Drops,DropsSpeed);
            Pick_up();
        }

        private void DropObjects(PictureBox[] array,int speed)
        {
            for (int i = 0; i< array.Length;i++)
            {
                array[i].Visible = true;
                array[i].Top += speed;
                if(array[i].Top>this.Height)
                {
                    array[i].Location = new Point((i + 1) * 100, -200);
                }
            }
        }

        private void Pick_up()
        {
            for (int i=0; i<Drops.Length;i++)
            {
                if (Player.Bounds.IntersectsWith(Drops[i].Bounds))
                {
                    Drops[i].Visible = false;
                }
            }
        }
    }
}
