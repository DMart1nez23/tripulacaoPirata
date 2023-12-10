namespace Jogo_2
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.Player = new System.Windows.Forms.PictureBox();
            this.MoveRight = new System.Windows.Forms.Timer(this.components);
            this.MoveLeft = new System.Windows.Forms.Timer(this.components);
            this.DropTimer = new System.Windows.Forms.Timer(this.components);
            ((System.ComponentModel.ISupportInitialize)(this.Player)).BeginInit();
            this.SuspendLayout();
            // 
            // Player
            // 
            this.Player.BackColor = System.Drawing.Color.Transparent;
            this.Player.Image = ((System.Drawing.Image)(resources.GetObject("Player.Image")));
            this.Player.Location = new System.Drawing.Point(257, 403);
            this.Player.Name = "Player";
            this.Player.Size = new System.Drawing.Size(104, 104);
            this.Player.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.Player.TabIndex = 0;
            this.Player.TabStop = false;
            // 
            // MoveRight
            // 
            this.MoveRight.Interval = 5;
            this.MoveRight.Tick += new System.EventHandler(this.timer2_Tick);
            // 
            // MoveLeft
            // 
            this.MoveLeft.Interval = 5;
            this.MoveLeft.Tick += new System.EventHandler(this.MoveLeft_Tick);
            // 
            // DropTimer
            // 
            this.DropTimer.Enabled = true;
            this.DropTimer.Tick += new System.EventHandler(this.DropTimer_Tick);
            // 
            // Form1
            // 
            this.ClientSize = new System.Drawing.Size(582, 553);
            this.Controls.Add(this.Player);
            this.Name = "Form1";
            this.Load += new System.EventHandler(this.Form1_Load);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyUp);
            ((System.ComponentModel.ISupportInitialize)(this.Player)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.PictureBox Player;
        private System.Windows.Forms.Timer MoveRight;
        private System.Windows.Forms.Timer MoveLeft;
        private System.Windows.Forms.Timer DropTimer;
    }
}

