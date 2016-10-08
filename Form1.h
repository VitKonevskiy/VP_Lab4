#pragma once
#include <math.h>
#include <string>
#include <string.h>
namespace ex14 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

	private: Graphics^ g;
			 bool flag;
			 int N;									//���-�� ��������� ������
			 int* data ;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label1;
			 array<Label^>^ arrayLabel;
			 System::Windows::Forms::TextBox^ test;
			 array<System::Windows::Forms::Label^>^ArrLab;
			 array<System::Windows::Forms::TextBox^>^ArrText;
			 array<System::String^>^ArrStr;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;


	public:
		String ^Names;
		bool secondPush;
		MyForm(void)
		{
			InitializeComponent();
			g = this->CreateGraphics();
			//
			//TODO: Add the constructor code here
			//
			flag = true;
			secondPush = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Calibri", 21.75F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(594, 36);
			this->label1->TabIndex = 2;
			this->label1->Text = L"�����: \"���� �� � ��� �������� ��������\?\"";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(121, 103);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Ok";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(15, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(181, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"������� ���-�� ��������� ������:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(203, 60);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 20);
			this->textBox1->TabIndex = 5;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(230, 114);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(418, 13);
			this->label3->TabIndex = 6;
			this->label3->Text = L"������� ������� ������. �� ������ ������� - ������� ���������������� ������";
			this->label3->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(762, 491);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::MyForm_Paint);
			this->Resize += gcnew System::EventHandler(this, &MyForm::MyForm_Resize);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		/*
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Refresh();

	data = new float[3];
	data[0] = 0.1f;				//���
	data[1] = 0.3f;				//�����
	data[2] = 0.6f;

	//	Names = gcnew String("���", "�����", "������", "�����", "�������", "�����", "��������");

	array<Color>^ color = gcnew array<Color>(7);
	color[0] = Color::LightCoral;
	color[1] = Color::Salmon;
	color[2] = Color::Khaki;
	color[3] = Color::Brown;
	color[4] = Color::GreenYellow;
	color[5] = Color::Maroon;
	color[6] = Color::MediumVioletRed;
	SolidBrush^ brush1 = gcnew SolidBrush(Color::Black);

	//	int n = 7;
	int n = 2;

	int x0 = 50;         //���������� ������ ���������
	int y0 = 100;

	int x1, y1; // ���������� ����� ������ ����
	int x2, y2; // ���������� ����� ����� ����
	double a1, a2; // ���� ����� ���� �� � �������,
				   // ��������������� ������

	int R = 80;    //������ ���������
	int D = 160;   //������� ���������
	double TORAD = 0.0174532;

	a1 = 0;
	int i = 1;
	    a2 = (a1 + 3.6*data[i] * 100);
		//�����. ������ ����:
		x1 = x0 + R*cos(a2*TORAD);
		y1 = y0 + R*sin(a2*TORAD);

		//����� ����� ����� ����
		x2 = x0 + R*cos(a1*TORAD);
		y2 = y0 + R*sin(a1*TORAD);

		brush1->Color = color[1];
	//	g->FillPie(brush1, x0, y0, 2 * D, 2 * D, a1, a2);

		brush1->Color = color[2];
		//g->FillPie(brush1, x0, y0, 2 * D, 2 * D, a2, a2-1);
		g->FillPie(brush1,x0, y0, 2 * D, 2 * D, 0, 11);
		brush1->Color = color[1];
		g->FillPie(brush1, x0, y0, 2 * D, 2 * D, 11, 20);
		
		g->FillPie(brush1, x0, y0, 2 * D, 2 * D, 20, 40);
		brush1->Color = color[3];
		g->FillPie(brush1, x0, y0, 2 * D, 2 * D, 200, 160);
}
*/
private: System::Void MyForm_Resize(System::Object^  sender, System::EventArgs^  e) {
}

	private: System::Void MyForm_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {

	/*	int n = 7;					//���-�� ��������
									//��������� ��������
		data = new float[n];
		data[0] = 0.4f;				//���
		data[1] = 0.3f;				//�����
		data[2] = 0.22f;			//������
		data[3] = 0.03f;			//�����
		data[4] = 0.03f;			//�������
		data[5] = 0.01f;			//�����
		data[6] = 0.01f;			//��������

		String^ s0 = "40% ���";
		String^ s1 = "30% �����";
		String^ s2 = "22% ������";
		String^ s3 = " 3% �����";
		String^ s4 = " 3% �������";
		String^ s5 = " 1% �����";
		String^ s6 = " 1% ��������";

								
		//������ ������ ��� ��������
		array<Color>^ color = gcnew array<Color>(n);
		color[0] = Color::FromArgb(110, 214, 165);
		color[1] = Color::DarkViolet;
		color[2] = Color::Khaki;
		color[3] = Color::Brown;
		color[4] = Color::Orange;
		color[5] = Color::RoyalBlue;
		color[6] = Color::FromArgb(133, 52, 52);

		//����� ��� ��������
		SolidBrush^ brush1 = gcnew SolidBrush(Color::Black);


		int lastAngle = 360;								//������������ ����
		int x0 = 50;										//���������� ������ ���������
		int y0 = 100;

		float a1, a2;										// ���� ����� ���� �� � �������,
															// ��������������� ������

		int D = 160;										//������� ���������
		double TORAD = 0.0174532;							//��� �������� � �������

		a1 = 0;
		for (int i = 0; i < n; i++)
		{
			a2 = (float)(a1 + 3.6f*data[i] * 100);			//��������� ����� ������� �������
			brush1->Color = color[i];						//�������� ���� ��� �������
			if (i < n - 1)									//��������� ������ ���������� ������������ �������� (������� ����)
			{
				g->FillPie(brush1, x0, y0, 2 * D, 2 * D, (int)a1, (int)(a2 - a1));				//��������� �������
			}
			else
			{
				lastAngle = 360 - a1;
				g->FillPie(brush1, x0, y0, 2 * D, 2 * D, (int)a1, lastAngle);					//��������� �������
			}
			a1 = a2;										//��������� �� ��������� ������
		}

		int X1 = 500;
		int Y1 = 100;
		for (int i = 0; i < n; i++)
		{
			brush1->Color = color[i];
			g->FillRectangle(brush1, X1, Y1, 20, 20);
			Y1 = Y1 + 35;
		}
		//������� ����� ��� ��������� �� ������
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
		X1 = X1 + 25;   //��������� �� �������� ���������

		//���������� ������ ��������� ������ �� ���� �����:
		PointF drawPoint0 = PointF(X1, 100);
		PointF drawPoint1 = PointF(X1, 135);
		PointF drawPoint2 = PointF(X1, 170);
		PointF drawPoint3 = PointF(X1, 205);
		PointF drawPoint4 = PointF(X1, 240);
		PointF drawPoint5 = PointF(X1, 275);
		PointF drawPoint6 = PointF(X1, 310);

		//����� ������ �����:
		brush1->Color = Color::Black;

		//������ ������.
		g->DrawString(s0, drawFont, brush1, drawPoint0);
		g->DrawString(s1, drawFont, brush1, drawPoint1);
		g->DrawString(s2, drawFont, brush1, drawPoint2);
		g->DrawString(s3, drawFont, brush1, drawPoint3);
		g->DrawString(s4, drawFont, brush1, drawPoint4);
		g->DrawString(s5, drawFont, brush1, drawPoint5);
		g->DrawString(s6, drawFont, brush1, drawPoint6);
*/
	}
	
private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {

}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (!secondPush)
	{
		
		try
		{
			this->label3->Visible = true;
			N = Convert::ToInt32(this->textBox1->Text);
			if (N < 0)
			{
				MessageBox::Show("������������ ���� ������!", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->textBox1->Text = "";
			}
			else
			{
				//	ArrLab = gcnew array<System::Windows::Forms::Label^>(N);
				ArrText = gcnew array<System::Windows::Forms::TextBox^>(2 * N);
				ArrStr = gcnew array<System::String^>(2 * N);
				int y = 140;						//��� ������� ��� ���������
				//������� TextBox
				for (int i = 0; i < N; i++)
				{
					this->ArrText[i] = gcnew System::Windows::Forms::TextBox();
					this->ArrText[i]->Location = System::Drawing::Point(303, y);
					this->ArrText[i]->Size = System::Drawing::Size(200, 20);
					this->Controls->Add(ArrText[i]);
					y += 25;
				}
				y = 140;
				//������� TextBox
				for (int i = N; i < 2 * N; i++)
				{
					this->ArrText[i] = gcnew System::Windows::Forms::TextBox();
					this->ArrText[i]->Location = System::Drawing::Point(550, y);
					this->ArrText[i]->Size = System::Drawing::Size(100, 20);
					this->Controls->Add(ArrText[i]);
					y += 25;
				}
				secondPush = true;
			}
		}
		catch (System::FormatException^ e)
		{
			MessageBox::Show("������������ ���� ������!", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox1->Text = "";
		}
		catch (System::OverflowException^ o)
		{
			MessageBox::Show("������������ ���� Int", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox1->Text = "";
		}
	}
	else
	{
		try
		{
			this->label3->Visible = false;
			this->button1->Visible = false;
			this->textBox1->Enabled = false;
			for (int i = 0; i < N; i++)
			{
				this->ArrStr[i] = gcnew System::String(this->ArrText[i]->Text);
				this->ArrText[i]->Visible = false;
			}
			data = new int[N];
			for (int i = N; i < 2 * N; i++)
			{
				this->ArrStr[i] = gcnew System::String(this->ArrText[i]->Text);
				data[i-N] = Convert::ToInt32(ArrStr[i]);
				this->ArrText[i]->Visible = false;
			}

			//������ ������ ��� ��������
			array<Color>^ color = gcnew array<Color>(7);//��� �������� �� �� �� ��
			color[0] = Color::FromArgb(110, 214, 165);
			color[1] = Color::DarkViolet;
			color[2] = Color::Khaki;
			color[3] = Color::Brown;
			color[4] = Color::Orange;
			color[5] = Color::RoyalBlue;
			color[6] = Color::FromArgb(133, 52, 52);

			//����� ��� ��������
			SolidBrush^ brush1 = gcnew SolidBrush(Color::Black);

			int lastAngle = 360;								//������������ ����
			int x0 = 50;										//���������� ������ ���������
			int y0 = 100;

			float a1, a2;										// ���� ����� ���� �� � �������,
																// ��������������� ������

			int D = 160;										//������� ���������
			double TORAD = 0.0174532;							//��� �������� � �������

			a1 = 0;
			for (int i = 0; i < N; i++)
			{
				a2 = (float)(a1 + 3.6f*(float)data[i]);			//��������� ����� ������� �������
				brush1->Color = color[i];						//�������� ���� ��� �������
				if (i < N - 1)									//��������� ������ ���������� ������������ �������� (������� ����)
				{
					g->FillPie(brush1, x0, y0, 2 * D, 2 * D, (int)a1, (int)(a2 - a1));				//��������� �������
				}
				else
				{
					lastAngle = 360 - a1;
					g->FillPie(brush1, x0, y0, 2 * D, 2 * D, (int)a1, lastAngle);					//��������� �������
				}
				a1 = a2;										//��������� �� ��������� ������
			}

			int X1 = 500;
			int Y1 = 100;
			for (int i = 0; i < N; i++)
			{
				brush1->Color = color[i];
				g->FillRectangle(brush1, X1, Y1, 20, 20);
				Y1 = Y1 + 35;
			}
			//������� ����� ��� ��������� �� ������
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
			X1 = X1 + 25;   //��������� �� �������� ���������
			int y = 100;

			//���������� ������ ��������� ������ �� �����:
			array<PointF>^ArrPoint = gcnew array<PointF>(N);
			for (int i = 0; i < N; i++)
			{
				ArrPoint[i] = PointF(X1, y);
				y += 35;
			}
							

			//����� ������ �����:
			brush1->Color = Color::Black;

			//������ ������.
			for (int i = 0; i < N; i++)
			{
				g->DrawString(ArrStr[i], drawFont, brush1, ArrPoint[i]);
			}

		}
		catch (System::FormatException^ e)
		{
			MessageBox::Show("������������ ���� ������!", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox1->Text = "";
		}
		catch (System::OverflowException^ o)
		{
			MessageBox::Show("������������ ���� Int", "������", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox1->Text = "";
		}
		
	}
	
}
};

}

