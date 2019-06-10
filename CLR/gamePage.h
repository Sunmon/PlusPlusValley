#pragma once
#include "Controller.h"
#include <array>
#include <msclr\marshal_cppstd.h>
#include <string>
#include <msclr\marshal_cppstd.h>

namespace CLRFInal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// gamePage�� ���� ����Դϴ�.
	//	matrix[x,y] : map tile
	//	MAX_X, MAX,Y : map�� tile �迭 �� 
	//	TILE_SIZE: �׸��� ��Ÿ�� �� Ÿ���� ������(px)
	//	setMatrixImgs(x,y):Ÿ�� �ϳ��ϳ��� �̹��� ����. background�� Ǯ/��, img�� ������Ʈ.
	//	void setMatrix(): ��ü �� �׸���
	//	imageList_MO: �� ������Ʈ �̹��� �����ϴ� ����Ʈ
	//	imageList_Player: �÷��̾� �̹��� �����ϴ� ����Ʈ
	/// </summary>
	public ref class gamePage : public System::Windows::Forms::Form
	{
	public:

		Controller* controller = Controller::getInstance();
		const int MAX_X = controller->map->MAX_X;
		const int MAX_Y = controller->map->MAX_Y;
		int TILE_SIZE;
		ImageList^ imgList_ground;
		ImageList^ imgList_MO;
		ImageList^ imgList_player;
		const int DRY = 0, WET = 1, GRASS = 2;	//imagelist_ground�� ���� ������ �̸� �����ذ�
		
	private: System::Windows::Forms::PictureBox^ picBox_player;
	public:
		cli::array<PictureBox^, 2> ^ matrix = gcnew cli::array<PictureBox^, 2>(MAX_X, MAX_Y);
		
		gamePage(void)
		{
			InitializeComponent();
			TILE_SIZE = pnl_background->Width / MAX_X;
			setImgList_MO();
			setImgList_ground();
			imgList_player = gcnew ImageList();
			
			setMatrix();
			//
			//TODO: ������ �ڵ带 ���⿡ �߰��մϴ�.
			//
		}

	protected:
		/// <summary>
		/// ��� ���� ��� ���ҽ��� �����մϴ�.
		/// </summary>
		~gamePage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ pnl_background;
	private: System::Windows::Forms::PictureBox^ picBox_dirt;
	private:
		/// <summary>
		/// �ʼ� �����̳� �����Դϴ�.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �����̳� ������ �ʿ��� �޼����Դϴ�. 
		/// �� �޼����� ������ �ڵ� ������� �������� ������.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(gamePage::typeid));
			this->pnl_background = (gcnew System::Windows::Forms::Panel());
			this->picBox_player = (gcnew System::Windows::Forms::PictureBox());
			this->picBox_dirt = (gcnew System::Windows::Forms::PictureBox());
			this->pnl_background->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_player))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_dirt))->BeginInit();
			this->SuspendLayout();
			// 
			// pnl_background
			// 
			this->pnl_background->Controls->Add(this->picBox_player);
			this->pnl_background->Controls->Add(this->picBox_dirt);
			this->pnl_background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_background->Location = System::Drawing::Point(0, 0);
			this->pnl_background->Name = L"pnl_background";
			this->pnl_background->Size = System::Drawing::Size(1262, 753);
			this->pnl_background->TabIndex = 0;
			this->pnl_background->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &gamePage::Pnl_background_Paint);
			// 
			// picBox_player
			// 
			this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_player.Image")));
			this->picBox_player->Location = System::Drawing::Point(460, 264);
			this->picBox_player->Name = L"picBox_player";
			this->picBox_player->Size = System::Drawing::Size(33, 63);
			this->picBox_player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBox_player->TabIndex = 1;
			this->picBox_player->TabStop = false;
			// 
			// picBox_dirt
			// 
			this->picBox_dirt->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_dirt.BackgroundImage")));
			this->picBox_dirt->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->picBox_dirt->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_dirt.Image")));
			this->picBox_dirt->Location = System::Drawing::Point(185, 113);
			this->picBox_dirt->Name = L"picBox_dirt";
			this->picBox_dirt->Size = System::Drawing::Size(31, 34);
			this->picBox_dirt->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBox_dirt->TabIndex = 0;
			this->picBox_dirt->TabStop = false;
			this->picBox_dirt->Click += gcnew System::EventHandler(this, &gamePage::PictureBox1_Click);
			// 
			// gamePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 753);
			this->Controls->Add(this->pnl_background);
			this->Name = L"gamePage";
			this->Text = L"gamePage";
			this->pnl_background->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_player))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_dirt))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void PictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	//��ü �� ȭ�鿡 �׸���
	private: void setMatrix()
	{
		for (int i = 0; i < MAX_X; i++)
		{
			for (int j = 0; j < MAX_Y; j++)
			{
				matrix[i, j] = gcnew System::Windows::Forms::PictureBox();
				setMatrixImgs(i, j);
				this->matrix[i,j]->Location = System::Drawing::Point(i*TILE_SIZE, j*TILE_SIZE);
				this->matrix[i,j]->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				this->matrix[i,j]->Size = System::Drawing::Size(TILE_SIZE, TILE_SIZE);

				//this->matrix[i,j]->TabIndex = 0;
				//this->matrix[i,j]->TabStop = false;

				this->pnl_background->Controls->Add(this->matrix[i,j]);
				this->matrix[i, j]->Show();
			}
		}

	}

	//Ÿ�� �ϳ��ϳ��� �̹��� ����. background�� Ǯ/��, img�� ������Ʈ.
	private: void setMatrixImgs(int x, int y)
	{
		//background ��/Ǯ ����
		int state = (controller->map->gettile(x, y)->getCanSeed()) ? DRY : GRASS;
		this->matrix[x, y]->BackgroundImage = imgList_ground->Images[state];

		//map object ����
		MapObject* objPtr = controller->map->gettile(x, y)->getObject();
		if (objPtr == nullptr || objPtr->getObjectType() == NULL) return;
		matrix[x, y]->Image = imgList_MO->Images[objPtr->getObjectType()];
	}


	private: System::Void Pnl_background_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	//string to System::string
	private: std::string system_to_string(System::String^ sys_str)
	{
		return  msclr::interop::marshal_as<std::string>(sys_str);
	}

	//System::string to std::string^
	private: System::String^ string_to_system(std::string str)
	{
		return  msclr::interop::marshal_as<String^>(str);
	}


	 void setImgList_MO()
	{
		 imgList_MO = gcnew ImageList();
		 imgList_MO->ColorDepth = ColorDepth::Depth32Bit;

		 //imgList_MO->ImageSize::StretchImage;

		 imgList_MO->Images->Add(Image::FromFile("./images/tree.png"));
		 imgList_MO->Images->Add(Image::FromFile("./images/stone.png"));

		 //TODO:�ӽ÷� �߰��س���. ����&npc�� �ٲ� ��
		 imgList_MO->Images->Add(Image::FromFile("./images/stone.png"));
		 imgList_MO->Images->Add(Image::FromFile("./images/stone.png"));
	}

	 void setImgList_ground()
	 {
		 imgList_ground = gcnew ImageList();
		 imgList_ground->ColorDepth = ColorDepth::Depth32Bit;

		 imgList_ground->Images->Add(Image::FromFile("./images/dryDirt.png"));
		 imgList_ground->Images->Add(Image::FromFile("./images/wetDirt.png"));
		 imgList_ground->Images->Add(Image::FromFile("./images/grass.png"));
	 }
};




}