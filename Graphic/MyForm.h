#pragma once
#include "MyFunctions.h"

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
			pn_axes = gcnew Pen(Color::Black, 3);
			pn_line = gcnew Pen(Color::Blue, 3);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbPlot))->BeginInit();
			this->SuspendLayout();
			// 
			// pbPlot
			// 
			this->pbPlot->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->pbPlot->Location = System::Drawing::Point(203, 12);
			this->pbPlot->Name = L"pbPlot";
			this->pbPlot->Size = System::Drawing::Size(904, 436);
			this->pbPlot->TabIndex = 0;
			this->pbPlot->TabStop = false;
			// 
			// btnPlot
			// 
			this->btnPlot->Location = System::Drawing::Point(555, 512);
			this->btnPlot->Name = L"btnPlot";
			this->btnPlot->Size = System::Drawing::Size(161, 69);
			this->btnPlot->TabIndex = 1;
			this->btnPlot->Text = L"Построить";
			this->btnPlot->UseVisualStyleBackColor = true;
			this->btnPlot->Click += gcnew System::EventHandler(this, &MyForm::btnPlot_Click);
			// 
			// tbXMax
			// 
			this->tbXMax->Location = System::Drawing::Point(1007, 512);
			this->tbXMax->Name = L"tbXMax";
			this->tbXMax->Size = System::Drawing::Size(100, 26);
			this->tbXMax->TabIndex = 2;
			this->tbXMax->Text = L"10";
			// 
			// tbYMin
			// 
			this->tbYMin->Location = System::Drawing::Point(1113, 422);
			this->tbYMin->Name = L"tbYMin";
			this->tbYMin->Size = System::Drawing::Size(100, 26);
			this->tbYMin->TabIndex = 3;
			this->tbYMin->Text = L"-10";
			// 
			// tbYMax
			// 
			this->tbYMax->Location = System::Drawing::Point(1113, 12);
			this->tbYMax->Name = L"tbYMax";
			this->tbYMax->Size = System::Drawing::Size(100, 26);
			this->tbYMax->TabIndex = 4;
			this->tbYMax->Text = L"10";
			// 
			// tbXMin
			// 
			this->tbXMin->Location = System::Drawing::Point(203, 512);
			this->tbXMin->Name = L"tbXMin";
			this->tbXMin->Size = System::Drawing::Size(100, 26);
			this->tbXMin->TabIndex = 5;
			this->tbXMin->Text = L"-10";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1225, 635);
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
		Brush^ br;
		Pen^ pn_axes, ^ pn_line;
		void clear(Image^ img, Brush^ b) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->FillRectangle(b, 0, 0, img->Width, img->Height);
		}
		void plot_axes(Image^ img, Pen^ pn, Point origin) {
			Graphics^ gr = Graphics::FromImage(img);
			gr->DrawLine(pn, 0, origin.Y, img->Width, origin.Y);
			gr->DrawLine(pn, origin.X, 0, origin.X, img->Height);
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
};
}
