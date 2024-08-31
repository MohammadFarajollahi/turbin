using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Windows.Forms.DataVisualization.Charting;
using System.Threading;

namespace girbox_auto
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            vScrollBar1.Value = 1000;
            label8.Text = vScrollBar1.Value.ToString();

            vScrollBar2.Value = 500;
            label22.Text = vScrollBar2.Value.ToString();

            trackBar1.Value = 500;
            label6.Text = "500";

            trackBar6.Value = 400;
            label19.Text = "400";

            radioButton6.Checked = true;
            radioButton5.Checked = false;

            label13.Text = "";


        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {
            updatePorts();          
            CheckForIllegalCrossThreadCalls = false;
        }

        private void updatePorts()
        {
            // Retrieve the list of all COM ports on your Computer
            string[] ports = SerialPort.GetPortNames();
            foreach (string port in ports)
            {
                cmbPortName.Items.Add(port);
            }
        }

        private SerialPort ComPort = new SerialPort();
        int select;
        private void button1_Click(object sender, EventArgs e)
        {
            if (ComPort.IsOpen)
            {
                disconnect();
            }
            else
            {
                connect();
            }
        }
             private void disconnect()
        {
            ComPort.Close();
            btnConnect.Text = "Connect";
            //btnSend.Enabled = false;
            //groupBox1.Enabled = true;

        
    }

        private void connect()
        {
            bool error = false;
            ComPort.PortName = cmbPortName.Text;
            ComPort.BaudRate = int.Parse("115200");      //convert Text to Integer
            ComPort.Parity = (Parity)Enum.Parse(typeof(Parity), "None"); //convert Text to Parity
            ComPort.DataBits = int.Parse("8");        //convert Text to Integer
            ComPort.StopBits = (StopBits)Enum.Parse(typeof(StopBits), "1");  //convert Text to stop bits

            try  //always try to use this try and catch method to open your port. 
                 //if there is an error your program will not display a message instead of freezing.
            {
                //Open Port
                ComPort.Open();
                ComPort.DataReceived += SerialPortDataReceived;  //Check for received data. When there is data in the receive buffer,
                                                                 //it will raise this event, we need to subscribe to it to know when there is data
            }
            catch (UnauthorizedAccessException) { error = true; }
            catch (System.IO.IOException) { error = true; }
            catch (ArgumentException) { error = true; }

            if (error) MessageBox.Show(this, "Could not open the COM port. Most likely it is already in use, has been removed, or is unavailable.", "COM Port unavailable", MessageBoxButtons.OK, MessageBoxIcon.Stop);


            //if the port is open, Change the Connect button to disconnect, enable the send button.
            //and disable the groupBox to prevent changing configuration of an open port.
            if (ComPort.IsOpen)
            {
                btnConnect.Text = "Disconnect";
               // btnSend.Enabled = true;
            }
        }

        private void sendData()
        {
            ComPort.Write(txtSend.Text);

            // Show in the terminal window 
            rtxtDataArea.ForeColor = Color.Green;    //write sent text data in green colour              
            txtSend.Clear();                       //clear screen after sending data        
        }
        int temp;
        private void SerialPortDataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            var serialPort = (SerialPort)sender;
            var data = serialPort.ReadExisting();
            SetText(data);
        }

        delegate void SetTextCallback(string text);
        private void SetText(string text)
        {
            // text = "s1,34,129,87Bs2,24,19,97Bs3,24,19,97Bs4,24,19,97B\r\n";
            if (text != "" && text != null)
            {
                string s = text;
                string[] twobackslash = s.Split('B');
                //for (int ii = 0; ii < twobackslash.Count(); ii++)
                //{
                //    if (twobackslash[ii] == "\r\n")
                //    {


                for (int i = 0; i < twobackslash.Count(); i++)
                {
                    string[] sensordata = twobackslash.ElementAt(i).Split(',');
                    for (int j = 0; j < sensordata.Count(); j++)
                    {
                        if (sensordata.ElementAt(0) == "s1")
                        {
                           
                            temp = Int32.Parse(sensordata.ElementAt(1));

                            //ybox1.Text = sensordata.ElementAt(2);
                            //zbox1.Text = sensordata.ElementAt(3);
                        }
                        if (sensordata.ElementAt(0) == "s2")
                        {
                           // xbox2.Text = sensordata.ElementAt(1);
                           // ybox2.Text = sensordata.ElementAt(2);
                           // zbox2.Text = sensordata.ElementAt(3);
                        }

                        if (sensordata.ElementAt(0) == "s3")
                        {
                            //xbox3.Text = sensordata.ElementAt(1);
                            //ybox3.Text = sensordata.ElementAt(2);
                            //zbox3.Text = sensordata.ElementAt(3);
                        }

                        if (sensordata.ElementAt(0) == "s4")
                        {
                           // xbox4.Text = sensordata.ElementAt(1);
                           // ybox4.Text = sensordata.ElementAt(2);
                            //zbox4.Text = sensordata.ElementAt(3);
                            //}
                            //}
                        }
                    }
                }
            }

           

            if (this.rtxtDataArea.InvokeRequired)
            {
                rtxtDataArea.ForeColor = Color.Green;    //write text data in Green colour

                SetTextCallback d = new SetTextCallback(SetText);
                this.Invoke(d, new object[] { text });
            }
            else
            {
                this.rtxtDataArea.AppendText(text);
            }
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (ComPort.IsOpen) ComPort.Close();  //close the port if open when exiting the application.
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
           
        }

        private void checkBox1_CheckedChanged_1(object sender, EventArgs e)
        {
            
        }
        int i;
        Chart chart1;
        
        private void timer1_Tick(object sender, EventArgs e)
        {

            i++;
            //aGauge1.Value = i;
            Random random = new Random();
            int randomNumber = random.Next(0, 50);
            //chart***************************************
            DataPoint dp1 = new DataPoint();
            DataPoint dp2 = new DataPoint();
            dp1.SetValueXY(i, randomNumber);
            dp2.SetValueXY(i, randomNumber);
           
            




            //DataPoint dp1 = new DataPoint();
            //dp1.SetValueXY(i, 10);
            //chart2.Series[0].Points.Add(dp1);
            //chart2.Series[0].ChartType =
            //SeriesChartType.Spline;

        }

        private void SplineChartExample()
        {
            
        }
        private void button1_Click_1(object sender, EventArgs e)
        {
            txtSend.Text = txtSend.Text;
            sendData();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            txtSend.Text = "MOTOR=OFF";
            sendData();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            txtSend.Text = "MOTOR=ON";
            sendData();
        }

        private void rtxtDataArea_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click_2(object sender, EventArgs e)
        {
            txtSend.Text = txtSend.Text;
            sendData();
        }

        private void vScrollBar2_Scroll(object sender, ScrollEventArgs e)
        {
           
        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            label6.Text = trackBar1.Value.ToString();
           // txtSend.Text = "sp:" + trackBar1.Value.ToString();
           // sendData();
           // Thread.Sleep(500);
          
        }

        private void vScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            label8.Text = vScrollBar1.Value.ToString();
            label13.Text = "";
            if (vScrollBar1.Value >= 4500)
            {
                vScrollBar1.Value = 5125;
                label8.Text = "5125";
                label13.Text = "move max";
            }

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (radioButton5.Checked == false) {
                txtSend.Text = "mu:" + label8.Text; //vScrollBar1.Value.ToString();
            }
            if (radioButton5.Checked == true)
            {
                txtSend.Text = "xu:" + vScrollBar1.Value.ToString();
            }

            sendData();
        }

        private void button5_Click(object sender, EventArgs e)
        {
            if (radioButton5.Checked == false)
            {
                txtSend.Text = "md:" + vScrollBar1.Value.ToString();
            }

            if (radioButton5.Checked == true)
            {
                txtSend.Text = "xd:" + vScrollBar1.Value.ToString();
            }
            sendData();
        }

        private void label7_Click(object sender, EventArgs e)
        {

        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            txtSend.Text = "sp:" + trackBar1.Value.ToString();
            sendData();
        }

        private void button3_Click_1(object sender, EventArgs e)
        {
           // txtSend.Text = "st:" + trackBar2.Value.ToString();
           // sendData();
        }

        private void button7_Click(object sender, EventArgs e)
        {
          //  txtSend.Text = "ac:" + trackBar3.Value.ToString();
          //  sendData();
        }

        private void trackBar2_Scroll(object sender, EventArgs e)
        {
            //label10.Text = trackBar2.Value.ToString();
        }

        private void trackBar3_Scroll(object sender, EventArgs e)
        {
            //label12.Text = trackBar3.Value.ToString();
        }

        private void label9_Click(object sender, EventArgs e)
        {

        }

        private void label13_Click(object sender, EventArgs e)
        {

        }

        private void button13_Click(object sender, EventArgs e)
        {

        }

        private void button10_Click(object sender, EventArgs e)
        {
            txtSend.Text = "yp:" + trackBar6.Value.ToString();
            sendData();
        }

        private void trackBar6_Scroll(object sender, EventArgs e)
        {
            label19.Text = trackBar6.Value.ToString();
           // txtSend.Text = "yp:" + trackBar6.Value.ToString();
           // sendData();
           // Thread.Sleep(500);
            
        }

        private void trackBar5_Scroll(object sender, EventArgs e)
        {
            //label18.Text = trackBar5.Value.ToString();
        }

        private void trackBar4_Scroll(object sender, EventArgs e)
        {
            //label17.Text = trackBar4.Value.ToString();
        }

        private void vScrollBar2_Scroll_1(object sender, ScrollEventArgs e)
        {
            label22.Text = vScrollBar2.Value.ToString();
        }

        private void button12_Click(object sender, EventArgs e)
        {
            txtSend.Text = "yu:" + vScrollBar2.Value.ToString();
            sendData();
        }

        private void button11_Click(object sender, EventArgs e)
        {
            txtSend.Text = "yd:" + vScrollBar2.Value.ToString();
            sendData();
        }

        private void button13_Click_1(object sender, EventArgs e)
        {
            txtSend.Text = "on:";
            sendData();
        }

        private void button14_Click(object sender, EventArgs e)
        {
            txtSend.Text = "of";
            sendData();
        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {
           
        }

        private void button3_Click_2(object sender, EventArgs e)
        {

            if (radioButton4.Checked == true)
            {
                txtSend.Text = "s1";
                sendData();
            }

            if (radioButton1.Checked == true)
            {
                txtSend.Text = "s4";
                sendData();
            }


            if (radioButton2.Checked == true)
            {
                txtSend.Text = "s6";
                sendData();
            }

            if (radioButton3.Checked == true)
            {
                txtSend.Text = "s8";
                sendData();
            }

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void label11_Click(object sender, EventArgs e)
        {

        }

        private void button7_Click_1(object sender, EventArgs e)
        {
            txtSend.Text = "mu:" + "50000";
            label13.Text = "halat amo saeid";
            sendData();
        }

        private void button8_Click(object sender, EventArgs e)
        {
            txtSend.Text = "xt";
            label13.Text = "start welding";
            sendData();
        }
    }
}
