#pragma once
#include "Controller.h"
#include "MyForm2.h"

#include <list>
#include <array>
#include <msclr\marshal_cppstd.h>
#include <string>
#include <msclr\marshal_cppstd.h>
#include <cassert>

namespace CLRFInal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// gamePage에 대한 요약입니다.
	//	matrix[x,y] : map tile
	//	MAX_X, MAX,Y : map의 tile 배열 수 
	//	TILE_SIZE: 그림상 나타낼 한 타일의 사이즈(px)
	//	setMatrixImgs(x,y):타일 하나하나의 이미지 설정. background는 풀/땅, img는 오브젝트.
	//	void setMatrix(): 전체 맵 그리기
	//	imageList_MO: 맵 오브젝트 이미지 저장하는 리스트
	//	imageList_Player: 플레이어 이미지 저장하는 리스트
	/// </summary>
	public ref class gamePage : public System::Windows::Forms::Form
	{
	public:

		Controller* controller = Controller::getInstance();
		Player* player = controller->getPlayer();
		System::ComponentModel::ComponentResourceManager^ rs;


		const int MAX_X = controller->map->MAX_X;
		const int MAX_Y = controller->map->MAX_Y;
		int TILE_SIZE;
		ImageList^ imgList_ground;
		ImageList^ imgList_MO;
		//ImageList^ imgList_player;

		int before_x, before_y;
		//List<Bitmap> imgList_player;
		const int DRY = 0, WET = 1, GRASS = 2;	//imagelist_ground에 쓰기 쉬우라고 이름 정해준것
		
		int moveState = 1;
		Timer animTimer;	//걷는 애니메이션을 위한 타이머
	private: System::ComponentModel::BackgroundWorker^ bgWorker_animate;
	private: System::Windows::Forms::Panel^ pnl_player;
	private: System::Windows::Forms::Panel^ pnl_npc;
	private: System::Windows::Forms::Panel^ pnl_item;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ icon_pos;

	private: System::Windows::Forms::Panel^ pnl_itemOpen;

	public:

	public:

	public:
		cli::array<PictureBox^, 2> ^ matrix = gcnew cli::array<PictureBox^, 2>(MAX_X, MAX_Y);
		
		gamePage(void)
		{
			InitializeComponent();
			TILE_SIZE = pnl_background->Width / MAX_X;
			setImgList_MO();
			setImgList_ground();
			//setImgList_player();
			
			setMatrix();
			this->picBox_player->Location = System::Drawing::Point(player->getX()*TILE_SIZE, player->gety() * TILE_SIZE - picBox_player->Height + TILE_SIZE);
			//this->pnl_player->Location = System::Drawing::Point(player->getX() * TILE_SIZE, player->gety() * TILE_SIZE - pnl_player->Height + TILE_SIZE);

			//
			//TODO: 생성자 코드를 여기에 추가합니다.
			//
		}

	protected:
		/// <summary>
		/// 사용 중인 모든 리소스를 정리합니다.
		/// </summary>
		~gamePage()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ picBox_player;

	private: System::Windows::Forms::Panel^ pnl_background;

	private:
		/// <summary>
		/// 필수 디자이너 변수입니다.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// 디자이너 지원에 필요한 메서드입니다. 
		/// 이 메서드의 내용을 코드 편집기로 수정하지 마세요.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(gamePage::typeid));
			this->pnl_background = (gcnew System::Windows::Forms::Panel());
			rs = resources;
			this->pnl_itemOpen = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->icon_pos = (gcnew System::Windows::Forms::Panel());
			this->pnl_item = (gcnew System::Windows::Forms::Panel());
			this->pnl_npc = (gcnew System::Windows::Forms::Panel());
			this->pnl_player = (gcnew System::Windows::Forms::Panel());
			this->picBox_player = (gcnew System::Windows::Forms::PictureBox());
			this->bgWorker_animate = (gcnew System::ComponentModel::BackgroundWorker());
			this->pnl_background->SuspendLayout();
			this->pnl_itemOpen->SuspendLayout();
			this->panel9->SuspendLayout();
			this->panel8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_player))->BeginInit();
			this->SuspendLayout();
			// 
			// pnl_background
			// 
			this->pnl_background->Controls->Add(this->pnl_itemOpen);
			this->pnl_background->Controls->Add(this->pnl_item);
			this->pnl_background->Controls->Add(this->pnl_npc);
			this->pnl_background->Controls->Add(this->pnl_player);
			this->pnl_background->Controls->Add(this->picBox_player);
			this->pnl_background->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnl_background->Location = System::Drawing::Point(0, 0);
			this->pnl_background->Name = L"pnl_background";
			this->pnl_background->Size = System::Drawing::Size(1262, 753);
			this->pnl_background->TabIndex = 0;
			this->pnl_background->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &gamePage::Pnl_background_Paint);
			// 
			// pnl_itemOpen
			// 
			this->pnl_itemOpen->Controls->Add(this->panel9);
			this->pnl_itemOpen->Controls->Add(this->panel8);
			this->pnl_itemOpen->Location = System::Drawing::Point(388, 85);
			this->pnl_itemOpen->Name = L"pnl_itemOpen";
			this->pnl_itemOpen->Size = System::Drawing::Size(190, 197);
			this->pnl_itemOpen->TabIndex = 10;
			this->pnl_itemOpen->Visible = false;
			// 
			// panel9
			// 
			this->panel9->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel9->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel9.BackgroundImage")));
			this->panel9->Controls->Add(this->button1);
			this->panel9->Location = System::Drawing::Point(3, 3);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(184, 28);
			this->panel9->TabIndex = 9;
			this->panel9->Visible = false;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->Font = (gcnew System::Drawing::Font(L"돋움체", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(129)));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(168, -3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(19, 20);
			this->button1->TabIndex = 0;
			this->button1->Text = L"X";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Visible = false;
			this->button1->Click += gcnew System::EventHandler(this, &gamePage::Button1_Click);
			// 
			// panel8
			// 
			this->panel8->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->panel8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel8.BackgroundImage")));
			this->panel8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel8->Controls->Add(this->icon_pos);
			this->panel8->Location = System::Drawing::Point(0, 25);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(190, 173);
			this->panel8->TabIndex = 8;
			this->panel8->Visible = false;
			// 
			// icon_pos
			// 
			this->icon_pos->BackColor = System::Drawing::Color::Transparent;
			this->icon_pos->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"icon_pos.BackgroundImage")));
			this->icon_pos->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->icon_pos->Location = System::Drawing::Point(14, 38);
			this->icon_pos->Margin = System::Windows::Forms::Padding(2);
			this->icon_pos->Name = L"icon_pos";
			this->icon_pos->Size = System::Drawing::Size(24, 23);
			this->icon_pos->TabIndex = 0;
			this->icon_pos->Visible = false;
			// 
			// pnl_item
			// 
			this->pnl_item->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->pnl_item->BackColor = System::Drawing::Color::Transparent;
			this->pnl_item->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_item.BackgroundImage")));
			this->pnl_item->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnl_item->Location = System::Drawing::Point(1212, 3);
			this->pnl_item->Name = L"pnl_item";
			this->pnl_item->Size = System::Drawing::Size(38, 41);
			this->pnl_item->TabIndex = 7;
			this->pnl_item->DoubleClick += gcnew System::EventHandler(this, &gamePage::Pnl_item_DoubleClick);
			// 
			// pnl_npc
			// 
			this->pnl_npc->BackColor = System::Drawing::Color::Transparent;
			this->pnl_npc->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_npc.BackgroundImage")));
			this->pnl_npc->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnl_npc->Location = System::Drawing::Point(507, 219);
			this->pnl_npc->Name = L"pnl_npc";
			this->pnl_npc->Size = System::Drawing::Size(34, 64);
			this->pnl_npc->TabIndex = 3;
			this->pnl_npc->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &gamePage::Pnl_npc_Paint);
			this->pnl_npc->DoubleClick += gcnew System::EventHandler(this, &gamePage::Pnl_npc_DoubleClick);
			// 
			// pnl_player
			// 
			this->pnl_player->BackColor = System::Drawing::Color::Transparent;
			this->pnl_player->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pnl_player.BackgroundImage")));
			this->pnl_player->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pnl_player->Enabled = false;
			this->pnl_player->Location = System::Drawing::Point(578, 219);
			this->pnl_player->Name = L"pnl_player";
			this->pnl_player->Size = System::Drawing::Size(34, 63);
			this->pnl_player->TabIndex = 2;
			this->pnl_player->Visible = false;
			// 
			// picBox_player
			// 
			this->picBox_player->BackColor = System::Drawing::Color::Transparent;
			this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"picBox_player.Image")));
			this->picBox_player->Location = System::Drawing::Point(653, 219);
			this->picBox_player->Name = L"picBox_player";
			this->picBox_player->Size = System::Drawing::Size(33, 63);
			this->picBox_player->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->picBox_player->TabIndex = 1;
			this->picBox_player->TabStop = false;
			// 
			// bgWorker_animate
			// 
			this->bgWorker_animate->DoWork += gcnew System::ComponentModel::DoWorkEventHandler(this, &gamePage::bgWorker_animate_DoWork);
			this->bgWorker_animate->ProgressChanged += gcnew System::ComponentModel::ProgressChangedEventHandler(this, &gamePage::BgWorker_animate_ProgressChanged);
			this->bgWorker_animate->RunWorkerCompleted += gcnew System::ComponentModel::RunWorkerCompletedEventHandler(this, &gamePage::BgWorker_animate_RunWorkerCompleted);
			// 
			// gamePage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1262, 753);
			this->Controls->Add(this->pnl_background);
			this->Name = L"gamePage";
			this->Text = L"gamePage";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &gamePage::movePlayer);
			this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &gamePage::do_nothing);
			this->pnl_background->ResumeLayout(false);
			this->pnl_itemOpen->ResumeLayout(false);
			this->panel9->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->picBox_player))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void PictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}

	//전체 맵 화면에 그리기
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

	//타일 하나하나의 이미지 설정. background는 풀/땅, img는 오브젝트.
	private: void setMatrixImgs(int x, int y)
	{
		//background 땅/풀 설정
		int state = (!controller->map->gettile(x, y)->getCanSeed()) ? GRASS: 
			controller->map->gettile(x,y)->getIsWet()? WET:DRY;
		this->matrix[x, y]->BackgroundImage = imgList_ground->Images[state];

		//map object 설정
		MapObject* objPtr = controller->map->gettile(x, y)->getObject();
		//if (objPtr == nullptr || objPtr->getObjectType() == NULL) return;
		if (controller->map->gettile(x, y)->getObject() == nullptr || controller->map->gettile(x, y)->getObject() == NULL)
		{
			this->matrix[x, y]->Image = nullptr;
			matrix[x, y]->Refresh();
			return;
		}

		matrix[x, y]->Image = imgList_MO->Images[controller->map->gettile(x, y)->getObject()->getObjectType()];
		if (controller->map->gettile(x, y)->getObject()->getObjectType() == ObjectType::npc) {

			int _x = x * TILE_SIZE;
			int _y = y * TILE_SIZE - pnl_npc->Height + TILE_SIZE;
			this->pnl_npc->Location = System::Drawing::Point(_x, _y);
		}

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

		 //TODO:임시로 추가해놓음. 씨앗&npc로 바꿀 것
		 imgList_MO->Images->Add(Image::FromFile("./images/seed.png"));
		 imgList_MO->Images->Add(Image::FromFile("./images/npc.png"));
	}

	 void setImgList_ground()
	 {
		 imgList_ground = gcnew ImageList();
		 imgList_ground->ColorDepth = ColorDepth::Depth32Bit;

		 imgList_ground->Images->Add(Image::FromFile("./images/dryDirt.png"));
		 imgList_ground->Images->Add(Image::FromFile("./images/wetDirt.png"));
		 imgList_ground->Images->Add(Image::FromFile("./images/grass.png"));
	 }
/*
	 void setImgList_player()
	 {
		 imgList_player = gcnew ImageList();
		 imgList_player->ColorDepth = ColorDepth::Depth32Bit;


		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_down4.png"));

		 imgList[4]-[7] : up
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_up4.png"));

		 imgList[8]-[11] : right
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_right4.png"));

		 imgList[12]-[15] : left
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left1.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left2.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left3.png"));
		 this->imgList_player->Images->Add(Image::FromFile("./images/Leah_left4.png"));
	 }*/


	
private: System::Void movePlayer(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	bgWorker_animate->WorkerReportsProgress = true;
	if (e->KeyValue == 32) action();
	else if(!bgWorker_animate->IsBusy) bgWorker_animate->RunWorkerAsync(e->KeyValue);

}
	
private: System::Void do_nothing(System::Object^ sender, System::Windows::Forms::PreviewKeyDownEventArgs^ e) {
	//this->picBox_player->Visible = false;
}


private: System::Void bgWorker_animate_DoWork(System::Object^ sender, System::ComponentModel::DoWorkEventArgs^ e) {

	before_x = player->getX();
	before_y = player->gety();

	player->move((int)(e->Argument));
	
	while (moveState++ < 5)
	{
		Sleep(100);
		//this->pnl_player->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(getStateStr() + moveState)));

		this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(getStateStr()+moveState)));
		bgWorker_animate->ReportProgress(moveState);
	}
	moveState = 1;
}
private: System::Void BgWorker_animate_ProgressChanged(System::Object^ sender, System::ComponentModel::ProgressChangedEventArgs^ e) {
	
	int _x = before_x * TILE_SIZE +  (player->getX() - before_x) * e->ProgressPercentage * TILE_SIZE / 4;
	//int _y = before_y * TILE_SIZE - pnl_player->Height + TILE_SIZE + (player->gety() - before_y) * e->ProgressPercentage * TILE_SIZE / 4;

	int _y = before_y * TILE_SIZE - picBox_player->Height + TILE_SIZE + (player->gety() - before_y) * e->ProgressPercentage * TILE_SIZE / 4;
	this->picBox_player->Location = System::Drawing::Point(_x, _y);
	this->picBox_player->BackColor = System::Drawing::Color::Transparent;
	//this->pnl_player->Location = System::Drawing::Point(_x, _y);
	//this->pnl_player->BackColor = System::Drawing::Color::Transparent;

}
private: System::Void BgWorker_animate_RunWorkerCompleted(System::Object^ sender, System::ComponentModel::RunWorkerCompletedEventArgs^ e) {
	this->picBox_player->Image = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(getStateStr() + moveState)));
	//this->pnl_player->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(getStateStr() + moveState)));
	int _x = player->getX() * TILE_SIZE;
	int _y = player->gety() * TILE_SIZE - picBox_player->Height + TILE_SIZE;
	//int _y = player->gety() * TILE_SIZE - pnl_player->Height + TILE_SIZE;
	this->picBox_player->Location = System::Drawing::Point(_x, _y);
	this->picBox_player->BackColor = System::Drawing::Color::Transparent;
	//this->pnl_player->Location = System::Drawing::Point(_x, _y);
	//this->pnl_player->BackColor = System::Drawing::Color::Transparent;


}

		 void action()
		 {
			 player->interact();
			 setMatrixImgs(player->getTarget()->getx(), player->getTarget()->gety());
		 }

		 System::String^ getStateStr()
		 {
			 std::string str[4] = { "left","right", "down", "up" };
			 return string_to_system(str[player->getStatue()]);
		 }

private: System::Void Pnl_npc_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}


//npc 클릭하면 상점 열리기
private: System::Void Pnl_npc_DoubleClick(System::Object^ sender, System::EventArgs^ e) {

	//Application::EnableVisualStyles();
	//Application::SetCompatibleTextRenderingDefault(false);

	CLRFInal::MyForm2 storeForm;
	storeForm.ShowDialog();
}
//아이템 버튼 클릭시
private: System::Void Pnl_item_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	pnl_itemOpen->Show();
	panel8->Show();
	panel9->Show();
	button1->Show();
	setItemList();
}
private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {
	//panel8->Visible = false;
	//panel9->Visible = false;
	//button1->Visible = false;
	pnl_itemOpen->Visible = false;
	pnl_player->Select();
	//FIXME: 안움직임
	//this->PreviewKeyDown += gcnew System::Windows::Forms::PreviewKeyDownEventHandler(this, &gamePage::do_nothing);
	//this->pnl_background->ResumeLayout(true);

	//this->pnl_background->ResumeLayout(false);
}

		 string setItemImg(Item* item)
		 {
			 string name = item->getName();
			 string src = "";
			//this->panel8->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"panel8.BackgroundImage")));
			 if (name == "딸기씨앗" || name == "strawSeed") src = "seed1";
			 else if (name == "배추씨앗") src = "seed2";
			 else if (name == "수박씨앗") src = "seed3";
			 else if (name == "랜덤씨앗") src = "seed4";
			 else if (name == "ax") src = "ax";
			 else if (name == "hammer") src = "hammer";
			 else if (name == "sprinkle") src = "sprinkle";
			 else if (name == "sickle") src = "sickle";
			 return src;

		 }

		 void setItemList()
		 {
			 Inventory* inven = controller->getPlayer()->getInven();
			 int _x = icon_pos->Location.X;
			 int _y = icon_pos->Location.Y;
			 for (auto& item : inven->items)
			 {

				 string src = setItemImg(item.first);
				 if (src == "") continue;

				 System::Windows::Forms::Panel^ newPanel = gcnew System::Windows::Forms::Panel();
				 newPanel->BackColor = System::Drawing::Color::Transparent;

				 newPanel->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(rs->GetObject(string_to_system(src))));
				 newPanel->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 newPanel->Margin = System::Windows::Forms::Padding(4);
				 newPanel->Size = System::Drawing::Size(24, 23);
				 newPanel->Location = System::Drawing::Point(_x, _y);
				 this->panel8->Controls->Add(newPanel);

				 //TODO: add event listner;;  아이템 교체


				 _x += icon_pos->Width + 2;
				 if (_x >= 24 * 6)
				 {
					 _x = icon_pos->Location.X;
					 _y += icon_pos->Height;
				 }
				 
			 }
		 }

};
}


