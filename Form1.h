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
			 int N;									//Кол-во вариантов ответа
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
			this->label1->Text = L"Опрос: \"Есть ли у вас домашние животные\?\"";
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
			this->label2->Text = L"Введите кол-во вариантов ответа:";
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
			this->label3->Text = L"Введите вариант ответа. Во второй колонке - процент соответствующего ответа";
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
	data[0] = 0.1f;				//Нет
	data[1] = 0.3f;				//Кошка
	data[2] = 0.6f;

	//	Names = gcnew String("Нет", "Кошка", "Собака", "Рыбка", "Попугай", "Хомяк", "Черепаха");

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

	int x0 = 50;         //Координаты центра диаграммы
	int y0 = 100;

	int x1, y1; // координата точки начала дуги
	int x2, y2; // координата точки конца дуги
	double a1, a2; // угол между осью ОХ и прямыми,
				   // ограничивающими сектор

	int R = 80;    //Радиус диаграммы
	int D = 160;   //Диаметр диаграммы
	double TORAD = 0.0174532;

	a1 = 0;
	int i = 1;
	    a2 = (a1 + 3.6*data[i] * 100);
		//коорд. начала дуги:
		x1 = x0 + R*cos(a2*TORAD);
		y1 = y0 + R*sin(a2*TORAD);

		//коорд точки конца дуги
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

	/*	int n = 7;					//Кол-во значений
									//Объявляем значения
		data = new float[n];
		data[0] = 0.4f;				//Нет
		data[1] = 0.3f;				//Кошка
		data[2] = 0.22f;			//Собака
		data[3] = 0.03f;			//Рыбка
		data[4] = 0.03f;			//Попугай
		data[5] = 0.01f;			//Хомяк
		data[6] = 0.01f;			//Черепаха

		String^ s0 = "40% Нет";
		String^ s1 = "30% Кошка";
		String^ s2 = "22% Собака";
		String^ s3 = " 3% Рыбка";
		String^ s4 = " 3% Попугай";
		String^ s5 = " 1% Хомяк";
		String^ s6 = " 1% Черепаха";

								
		//Массив цветов для закраски
		array<Color>^ color = gcnew array<Color>(n);
		color[0] = Color::FromArgb(110, 214, 165);
		color[1] = Color::DarkViolet;
		color[2] = Color::Khaki;
		color[3] = Color::Brown;
		color[4] = Color::Orange;
		color[5] = Color::RoyalBlue;
		color[6] = Color::FromArgb(133, 52, 52);

		//Кисть для закраски
		SolidBrush^ brush1 = gcnew SolidBrush(Color::Black);


		int lastAngle = 360;								//Максимальный Угол
		int x0 = 50;										//Координаты центра диаграммы
		int y0 = 100;

		float a1, a2;										// угол между осью ОХ и прямыми,
															// ограничивающими сектор

		int D = 160;										//Диаметр диаграммы
		double TORAD = 0.0174532;							//для перевода в радианы

		a1 = 0;
		for (int i = 0; i < n; i++)
		{
			a2 = (float)(a1 + 3.6f*data[i] * 100);			//Вычисляем левую границу сектора
			brush1->Color = color[i];						//выбираем цвет для сектора
			if (i < n - 1)									//Последний сектор необходимо отрисовывать отдельно (костыль имхо)
			{
				g->FillPie(brush1, x0, y0, 2 * D, 2 * D, (int)a1, (int)(a2 - a1));				//Отрисовка сектора
			}
			else
			{
				lastAngle = 360 - a1;
				g->FillPie(brush1, x0, y0, 2 * D, 2 * D, (int)a1, lastAngle);					//Отрисовка сектора
			}
			a1 = a2;										//Переходим на следующий сектор
		}

		int X1 = 500;
		int Y1 = 100;
		for (int i = 0; i < n; i++)
		{
			brush1->Color = color[i];
			g->FillRectangle(brush1, X1, Y1, 20, 20);
			Y1 = Y1 + 35;
		}
		//Создаем шрифт для отрисовки на экране
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
		X1 = X1 + 25;   //Смещаемся от цветовых квадратов

		//Координаты начала отрисовки каждой из семи строк:
		PointF drawPoint0 = PointF(X1, 100);
		PointF drawPoint1 = PointF(X1, 135);
		PointF drawPoint2 = PointF(X1, 170);
		PointF drawPoint3 = PointF(X1, 205);
		PointF drawPoint4 = PointF(X1, 240);
		PointF drawPoint5 = PointF(X1, 275);
		PointF drawPoint6 = PointF(X1, 310);

		//Берем черную кисть:
		brush1->Color = Color::Black;

		//Рисуем строки.
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
				MessageBox::Show("Некорректный ввод данных!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
				this->textBox1->Text = "";
			}
			else
			{
				//	ArrLab = gcnew array<System::Windows::Forms::Label^>(N);
				ArrText = gcnew array<System::Windows::Forms::TextBox^>(2 * N);
				ArrStr = gcnew array<System::String^>(2 * N);
				int y = 140;						//Для сдвигов при отрисовки
				//Создаем TextBox
				for (int i = 0; i < N; i++)
				{
					this->ArrText[i] = gcnew System::Windows::Forms::TextBox();
					this->ArrText[i]->Location = System::Drawing::Point(303, y);
					this->ArrText[i]->Size = System::Drawing::Size(200, 20);
					this->Controls->Add(ArrText[i]);
					y += 25;
				}
				y = 140;
				//Создаем TextBox
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
			MessageBox::Show("Некорректный ввод данных!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox1->Text = "";
		}
		catch (System::OverflowException^ o)
		{
			MessageBox::Show("Переполнение типа Int", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
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

			//Массив цветов для закраски
			array<Color>^ color = gcnew array<Color>(7);//Как допилить хз хз хз хз
			color[0] = Color::FromArgb(110, 214, 165);
			color[1] = Color::DarkViolet;
			color[2] = Color::Khaki;
			color[3] = Color::Brown;
			color[4] = Color::Orange;
			color[5] = Color::RoyalBlue;
			color[6] = Color::FromArgb(133, 52, 52);

			//Кисть для закраски
			SolidBrush^ brush1 = gcnew SolidBrush(Color::Black);

			int lastAngle = 360;								//Максимальный Угол
			int x0 = 50;										//Координаты центра диаграммы
			int y0 = 100;

			float a1, a2;										// угол между осью ОХ и прямыми,
																// ограничивающими сектор

			int D = 160;										//Диаметр диаграммы
			double TORAD = 0.0174532;							//для перевода в радианы

			a1 = 0;
			for (int i = 0; i < N; i++)
			{
				a2 = (float)(a1 + 3.6f*(float)data[i]);			//Вычисляем левую границу сектора
				brush1->Color = color[i];						//выбираем цвет для сектора
				if (i < N - 1)									//Последний сектор необходимо отрисовывать отдельно (костыль имхо)
				{
					g->FillPie(brush1, x0, y0, 2 * D, 2 * D, (int)a1, (int)(a2 - a1));				//Отрисовка сектора
				}
				else
				{
					lastAngle = 360 - a1;
					g->FillPie(brush1, x0, y0, 2 * D, 2 * D, (int)a1, lastAngle);					//Отрисовка сектора
				}
				a1 = a2;										//Переходим на следующий сектор
			}

			int X1 = 500;
			int Y1 = 100;
			for (int i = 0; i < N; i++)
			{
				brush1->Color = color[i];
				g->FillRectangle(brush1, X1, Y1, 20, 20);
				Y1 = Y1 + 35;
			}
			//Создаем шрифт для отрисовки на экране
			System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 16);
			X1 = X1 + 25;   //Смещаемся от цветовых квадратов
			int y = 100;

			//Координаты начала отрисовки каждой из строк:
			array<PointF>^ArrPoint = gcnew array<PointF>(N);
			for (int i = 0; i < N; i++)
			{
				ArrPoint[i] = PointF(X1, y);
				y += 35;
			}
							

			//Берем черную кисть:
			brush1->Color = Color::Black;

			//Рисуем строки.
			for (int i = 0; i < N; i++)
			{
				g->DrawString(ArrStr[i], drawFont, brush1, ArrPoint[i]);
			}

		}
		catch (System::FormatException^ e)
		{
			MessageBox::Show("Некорректный ввод данных!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox1->Text = "";
		}
		catch (System::OverflowException^ o)
		{
			MessageBox::Show("Переполнение типа Int", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->textBox1->Text = "";
		}
		
	}
	
}
};

}

