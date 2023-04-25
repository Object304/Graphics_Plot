#pragma once
#include "MyFunctions.h"
#include <cmath>
namespace Graphic {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			pbPlot->Image = gcnew Bitmap(pbPlot->Width, pbPlot->Height);
			br = gcnew SolidBrush(Color::White);
			br_text = gcnew SolidBrush(Color::Black);
			pn_axes = gcnew Pen(Color::Black, 3);
			pn_line = gcnew Pen(Color::Blue, 3);
			pn_grid = gcnew Pen(Color::Gray, 1);
			printFont = gcnew System::Drawing::Font("Arial", 8);
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbPlot;
	protected:

	protected:
	private: System::Windows::Forms::Button^ btnPlot;
	private: System::Windows::Forms::TextBox^ tbXMax;
	private: System::Windows::Forms::TextBox^ tbYMin;
	private: System::Windows::Forms::TextBox^ tbYMax;
	private: System::Windows::Forms::TextBox^ tbXMin;
	private: System::Windows::Forms::Button^ btn_moveDown;
	private: System::Windows::Forms::Button^ btn_moveUp;
	private: System::Windows::Forms::Button^ btn_scaleUp;
	private: System::Windows::Forms::Button^ btn_scaleDown;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ btn_moveLeft;
	private: System::Windows::Forms::Button^ btn_moveRight;
	private: System::Windows::Forms::Button^ btn_scaleOut;
	private: System::Windows::Forms::Button^ btn_scaleIn;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pbPlot = (gcnew System::Windows::Forms::PictureBox());
			this->btnPlot = (gcnew System::Windows::Forms::Button());
			this->tbXMax = (gcnew System::Windows::Forms::TextBox());
			this->tbYMin = (gcnew System::Windows::Forms::TextBox());
			this->tbYMax = (gcnew System::Windows::Forms::TextBox());
			this->tbXMin = (gcnew System::Windows::Forms::TextBox());
			this->btn_moveDown = (gcnew System::Windows::Forms::Button());
			this->btn_moveUp = (gcnew System::Windows::Forms::Button());
			this->btn_scaleUp = (gcnew System::Windows::Forms::Button());
			this->btn_scaleDown = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btn_moveLeft = (gcnew System::Windows::Forms::Button());
			this->btn_moveRight = (gcnew System::Windows::Forms::Button());
			this->btn_scaleOut = (gcnew System::Windows::Forms::Button());
			this->btn_scaleIn = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlot))->BeginInit();
			this->SuspendLayout();
			// 
			// pbPlot
			// 
			this->pbPlot->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbPlot->Location = System::Drawing::Point(12, 12);
			this->pbPlot->Name = L"pbPlot";
			this->pbPlot->Size = System::Drawing::Size(904, 436);
			this->pbPlot->TabIndex = 0;
			this->pbPlot->TabStop = false;
			// 
			// btnPlot
			// 
			this->btnPlot->Location = System::Drawing::Point(1052, 529);
			this->btnPlot->Name = L"btnPlot";
			this->btnPlot->Size = System::Drawing::Size(161, 94);
			this->btnPlot->TabIndex = 1;
			this->btnPlot->Text = L"Построить";
			this->btnPlot->UseVisualStyleBackColor = true;
			this->btnPlot->Click += gcnew System::EventHandler(this, &MyForm::btnPlot_Click);
			// 
			// tbXMax
			// 
			this->tbXMax->Location = System::Drawing::Point(816, 454);
			this->tbXMax->Name = L"tbXMax";
			this->tbXMax->Size = System::Drawing::Size(100, 26);
			this->tbXMax->TabIndex = 2;
			this->tbXMax->Text = L"10";
			// 
			// tbYMin
			// 
			this->tbYMin->Location = System::Drawing::Point(922, 422);
			this->tbYMin->Name = L"tbYMin";
			this->tbYMin->Size = System::Drawing::Size(100, 26);
			this->tbYMin->TabIndex = 3;
			this->tbYMin->Text = L"-5";
			// 
			// tbYMax
			// 
			this->tbYMax->Location = System::Drawing::Point(922, 12);
			this->tbYMax->Name = L"tbYMax";
			this->tbYMax->Size = System::Drawing::Size(100, 26);
			this->tbYMax->TabIndex = 4;
			this->tbYMax->Text = L"5";
			// 
			// tbXMin
			// 
			this->tbXMin->Location = System::Drawing::Point(12, 454);
			this->tbXMin->Name = L"tbXMin";
			this->tbXMin->Size = System::Drawing::Size(100, 26);
			this->tbXMin->TabIndex = 5;
			this->tbXMin->Text = L"-10";
			// 
			// btn_moveDown
			// 
			this->btn_moveDown->Location = System::Drawing::Point(922, 347);
			this->btn_moveDown->Name = L"btn_moveDown";
			this->btn_moveDown->Size = System::Drawing::Size(75, 69);
			this->btn_moveDown->TabIndex = 6;
			this->btn_moveDown->Text = L"|\r\n|\r\n\\/";
			this->btn_moveDown->UseVisualStyleBackColor = true;
			this->btn_moveDown->Click += gcnew System::EventHandler(this, &MyForm::btn_moveDown_Click);
			// 
			// btn_moveUp
			// 
			this->btn_moveUp->Location = System::Drawing::Point(922, 44);
			this->btn_moveUp->Name = L"btn_moveUp";
			this->btn_moveUp->Size = System::Drawing::Size(75, 69);
			this->btn_moveUp->TabIndex = 7;
			this->btn_moveUp->Text = L"/\\\r\n|\r\n|";
			this->btn_moveUp->UseVisualStyleBackColor = true;
			this->btn_moveUp->Click += gcnew System::EventHandler(this, &MyForm::btn_moveUp_Click);
			// 
			// btn_scaleUp
			// 
			this->btn_scaleUp->Location = System::Drawing::Point(1051, 44);
			this->btn_scaleUp->Name = L"btn_scaleUp";
			this->btn_scaleUp->Size = System::Drawing::Size(75, 69);
			this->btn_scaleUp->TabIndex = 8;
			this->btn_scaleUp->Text = L"/\\\r\n|\r\n\\/";
			this->btn_scaleUp->UseVisualStyleBackColor = true;
			this->btn_scaleUp->Click += gcnew System::EventHandler(this, &MyForm::btn_scaleUp_Click);
			// 
			// btn_scaleDown
			// 
			this->btn_scaleDown->Location = System::Drawing::Point(1051, 347);
			this->btn_scaleDown->Name = L"btn_scaleDown";
			this->btn_scaleDown->Size = System::Drawing::Size(75, 69);
			this->btn_scaleDown->TabIndex = 9;
			this->btn_scaleDown->Text = L"\\/\r\n|\r\n/\\";
			this->btn_scaleDown->UseVisualStyleBackColor = true;
			this->btn_scaleDown->Click += gcnew System::EventHandler(this, &MyForm::btn_scaleDown_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(918, 215);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(86, 40);
			this->label1->TabIndex = 10;
			this->label1->Text = L"Переме-\r\nщать по Y";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(1047, 215);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(100, 40);
			this->label2->TabIndex = 11;
			this->label2->Text = L"Масштаби-\r\nровать по Y";
			// 
			// btn_moveLeft
			// 
			this->btn_moveLeft->Location = System::Drawing::Point(118, 454);
			this->btn_moveLeft->Name = L"btn_moveLeft";
			this->btn_moveLeft->Size = System::Drawing::Size(75, 69);
			this->btn_moveLeft->TabIndex = 12;
			this->btn_moveLeft->Text = L"<====";
			this->btn_moveLeft->UseVisualStyleBackColor = true;
			this->btn_moveLeft->Click += gcnew System::EventHandler(this, &MyForm::btn_moveLeft_Click);
			// 
			// btn_moveRight
			// 
			this->btn_moveRight->Location = System::Drawing::Point(735, 454);
			this->btn_moveRight->Name = L"btn_moveRight";
			this->btn_moveRight->Size = System::Drawing::Size(75, 69);
			this->btn_moveRight->TabIndex = 13;
			this->btn_moveRight->Text = L"====>";
			this->btn_moveRight->UseVisualStyleBackColor = true;
			this->btn_moveRight->Click += gcnew System::EventHandler(this, &MyForm::btn_moveRight_Click);
			// 
			// btn_scaleOut
			// 
			this->btn_scaleOut->Location = System::Drawing::Point(118, 529);
			this->btn_scaleOut->Name = L"btn_scaleOut";
			this->btn_scaleOut->Size = System::Drawing::Size(75, 69);
			this->btn_scaleOut->TabIndex = 14;
			this->btn_scaleOut->Text = L"<===>";
			this->btn_scaleOut->UseVisualStyleBackColor = true;
			this->btn_scaleOut->Click += gcnew System::EventHandler(this, &MyForm::btn_scaleOut_Click);
			// 
			// btn_scaleIn
			// 
			this->btn_scaleIn->Location = System::Drawing::Point(735, 529);
			this->btn_scaleIn->Name = L"btn_scaleIn";
			this->btn_scaleIn->Size = System::Drawing::Size(75, 69);
			this->btn_scaleIn->TabIndex = 15;
			this->btn_scaleIn->Text = L">===<";
			this->btn_scaleIn->UseVisualStyleBackColor = true;
			this->btn_scaleIn->Click += gcnew System::EventHandler(this, &MyForm::btn_scaleIn_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(404, 478);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 20);
			this->label3->TabIndex = 16;
			this->label3->Text = L"Перемещать по X";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(389, 553);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(179, 20);
			this->label4->TabIndex = 17;
			this->label4->Text = L"Масштабировать по X";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1225, 635);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->btn_scaleIn);
			this->Controls->Add(this->btn_scaleOut);
			this->Controls->Add(this->btn_moveRight);
			this->Controls->Add(this->btn_moveLeft);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btn_scaleDown);
			this->Controls->Add(this->btn_scaleUp);
			this->Controls->Add(this->btn_moveUp);
			this->Controls->Add(this->btn_moveDown);
			this->Controls->Add(this->tbXMin);
			this->Controls->Add(this->tbYMax);
			this->Controls->Add(this->tbYMin);
			this->Controls->Add(this->tbXMax);
			this->Controls->Add(this->btnPlot);
			this->Controls->Add(this->pbPlot);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlot))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		Brush^ br, ^ br_text;
		Pen^ pn_axes, ^ pn_line, ^ pn_grid;
		System::Drawing::Font^ printFont;
		void clear(Image^ img, Brush^ b) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->FillRectangle(b, 0, 0, img->Width, img->Height);
		}
		void plot_grid(Image^ img, Pen^ pn, Point origin, 
			double xs, double ys, double xmin, 
			double xmax, double ymin, double ymax) {
			Graphics^ gr = Graphics::FromImage(img);
			for (int i = 0, j = 0; i < (abs(xmin) + abs(xmax)) / (1 / xs); i += xs, j++) {
				gr->DrawLine(pn, origin.X + i, 0, origin.X + i, img->Height);
				gr->DrawLine(pn, origin.X - i, 0, origin.X - i, img->Height);
			}
			for (int i = 0, j = 0; i < (abs(ymin) + abs(ymax)) / (1 / ys); i += ys, j++) {
				gr->DrawLine(pn, 0, origin.Y + i, img->Width, origin.Y + i);
				gr->DrawLine(pn, 0, origin.Y - i, img->Width, origin.Y - i);
			}
			gr->FillRectangle(br, 0, img->Height - 20, img->Width, 20);
			gr->FillRectangle(br, 0, 0, 20, img->Height);
			for (int i = 0, j = 0; i < (abs(xmin) + abs(xmax)) / (1 / xs); i += xs, j++) {
				gr->DrawString(Convert::ToString(j), printFont, br_text, (origin.X + i - 5), img->Height - 20);
				gr->DrawString(Convert::ToString(-j), printFont, br_text, (origin.X - i - 5), img->Height - 20);
			}
			for (int i = 0, j = 0; i < (abs(ymin) + abs(ymax)) / (1 / ys); i += ys, j++) {
				gr->DrawString(Convert::ToString(j), printFont, br_text, 0, origin.Y - i - 5);
				gr->DrawString(Convert::ToString(-j), printFont, br_text, 0, origin.Y + i - 5);
			}
			gr->FillRectangle(br, 0, img->Height - 20, 20, 20);
		}
		void plot_axes(Image^ img, Pen^ pn, Point origin) {
			Graphics^ gr = Graphics::FromImage(img);
			//plot_grid(img, pn_grid, origin);
			gr->DrawLine(pn, 0, origin.Y, img->Width, origin.Y);
			gr->DrawString("X", printFont, br_text, img->Width - 20, origin.Y - 20);
			gr->DrawLine(pn, origin.X, 0, origin.X, img->Height);
			gr->DrawString("Y", printFont, br_text, origin.X - 20, 0);
		}
		void plot(double (*f)(double), 
			double xmin, 
			double xmax,
			double ymin,
			double ymax,
			Image^ img) {
				clear(img, br);
				double w = img->Width, h = img->Height;
				double xs = (xmax - xmin) / w,
					ys = (ymax - ymin) / h;
				Point origin(-xmin / xs, ymax / ys);
				plot_axes(img, pn_axes, origin);
				plot_grid(img, pn_grid, origin, 1 / xs, 1 / ys, xmin, xmax, ymin, ymax);
				Graphics^ gr = Graphics::FromImage(img);
				int y_pix = (ymax - f(xmin)) / ys;
				for (int x_pix1 = 1; x_pix1 < w; x_pix1++) {
					double x = xmin + x_pix1 * xs,
						y = f(x);
					int y_pix1 = (ymax - y) / ys;

					gr->DrawLine(pn_line, x_pix1 - 1, y_pix, x_pix1, y_pix1);
					y_pix = y_pix1;
				}
		}
private: System::Void btnPlot_Click(System::Object^ sender, System::EventArgs^ e) {
	double xmin = Convert::ToDouble(tbXMin->Text),
		xmax = Convert::ToDouble(tbXMax->Text),
		ymin = Convert::ToDouble(tbYMin->Text),
		ymax = Convert::ToDouble(tbYMax->Text);
	plot(/*&sinc*/&sqr, xmin, xmax, ymin, ymax, pbPlot->Image);
	pbPlot->Refresh();

	/*clear(pbPlot->Image, br);
	plot_axes(pbPlot->Image, pn_axes, Point(100, 100));
	pbPlot->Refresh();*/
}
private: System::Void btn_moveLeft_Click(System::Object^ sender, System::EventArgs^ e) {
	tbXMin->Text = Convert::ToString(Convert::ToDouble(tbXMin->Text) - 1);
	tbXMax->Text = Convert::ToString(Convert::ToDouble(tbXMax->Text) - 1);
	btnPlot_Click(sender, e);
}
private: System::Void btn_moveRight_Click(System::Object^ sender, System::EventArgs^ e) {
	tbXMin->Text = Convert::ToString(Convert::ToDouble(tbXMin->Text) + 1);
	tbXMax->Text = Convert::ToString(Convert::ToDouble(tbXMax->Text) + 1);
	btnPlot_Click(sender, e);
}
private: System::Void btn_moveUp_Click(System::Object^ sender, System::EventArgs^ e) {
	tbYMin->Text = Convert::ToString(Convert::ToDouble(tbYMin->Text) + 1);
	tbYMax->Text = Convert::ToString(Convert::ToDouble(tbYMax->Text) + 1);
	btnPlot_Click(sender, e);
}
private: System::Void btn_moveDown_Click(System::Object^ sender, System::EventArgs^ e) {
	tbYMin->Text = Convert::ToString(Convert::ToDouble(tbYMin->Text) - 1);
	tbYMax->Text = Convert::ToString(Convert::ToDouble(tbYMax->Text) - 1);
	btnPlot_Click(sender, e);
}
private: System::Void btn_scaleOut_Click(System::Object^ sender, System::EventArgs^ e) {
	tbXMin->Text = Convert::ToString(Convert::ToDouble(tbXMin->Text) + 1);
	tbXMax->Text = Convert::ToString(Convert::ToDouble(tbXMax->Text) - 1);
	btnPlot_Click(sender, e);
}
private: System::Void btn_scaleIn_Click(System::Object^ sender, System::EventArgs^ e) {
	tbXMin->Text = Convert::ToString(Convert::ToDouble(tbXMin->Text) - 1);
	tbXMax->Text = Convert::ToString(Convert::ToDouble(tbXMax->Text) + 1);
	btnPlot_Click(sender, e);
}
private: System::Void btn_scaleUp_Click(System::Object^ sender, System::EventArgs^ e) {
	tbYMin->Text = Convert::ToString(Convert::ToDouble(tbYMin->Text) + 1);
	tbYMax->Text = Convert::ToString(Convert::ToDouble(tbYMax->Text) - 1);
	btnPlot_Click(sender, e);
}
private: System::Void btn_scaleDown_Click(System::Object^ sender, System::EventArgs^ e) {
	tbYMin->Text = Convert::ToString(Convert::ToDouble(tbYMin->Text) - 1);
	tbYMax->Text = Convert::ToString(Convert::ToDouble(tbYMax->Text) + 1);
	btnPlot_Click(sender, e);
}
};
}
