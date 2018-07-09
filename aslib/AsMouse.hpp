//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	//マウスID
	enum :size_t {
		MOUSE_LEFT,
		MOUSE_RIGHT,
		MOUSE_MIDDLE,
		MOUSE_4,
		MOUSE_5,
		MOUSE_6,
		MOUSE_7,
		MOUSE_8,
		MOUSE_9,
		MOUSE_10,
	};

	//マウスのボタン数
	constexpr size_t mouse_button_num = 10;


	//マウス位置を記録する関数
	const Pos2 asMousePosSave(const bool b_, const Pos2& p_ = pos2_0)
	{
		static Pos2 p;
		if (b_) p = p_;
		return p;
	}

	//マウスの位置
	const Pos2 mousePos()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		int mouse_x = 0, mouse_y = 0;
		DxLib::GetMousePoint(&mouse_x, &mouse_y);

		Pos2 pos;
		pos(int32_t(mouse_x), int32_t(mouse_y));
		return pos;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return Pos2(int32_t(s3d::Cursor::Pos().x), int32_t(s3d::Cursor::Pos().y));
#elif defined(ASLIB_INCLUDE_OF)
		return asMousePosSave(false);
#elif defined(ASLIB_INCLUDE_TP)
		return Pos2();
#else //Console
		return Pos2();
#endif
	}

	inline const PosA4 mousePos(const int32_t l_)
	{
		return PosA4(mousePos(), l_);
	}
	inline const PosA4 mousePos(const int32_t w_, const int32_t h_)
	{
		return PosA4(mousePos(), w_, h_);
	}

	//マウスのホイール回転量(奥:負 手前:正)
	inline const int32_t mouseWheel()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::GetMouseWheelRotVol(TRUE));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return int32_t(s3d::Mouse::Wheel());
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
		return 0;
#else //Console
		return 0;
#endif
	}

	//ウィンドウサイズを記録する関数
	const bool* const asMouseButtonSave(const bool b_, const bool c_=false,const bool p_ = false, const size_t s_ = 0)
	{
		static bool p[mouse_button_num];
		if (c_) for (size_t i = 0; i < mouse_button_num; ++i) p[i] = false;
		if (b_) p[s_] = p_;
		return p;
	}

	inline void mouseButton(Counter count[mouse_button_num])
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		const int mouse_input = DxLib::GetMouseInput();
		count[MOUSE_LEFT].update((mouse_input & MOUSE_INPUT_LEFT) != 0);
		count[MOUSE_RIGHT].update((mouse_input & MOUSE_INPUT_RIGHT) != 0);
		count[MOUSE_MIDDLE].update((mouse_input & MOUSE_INPUT_MIDDLE) != 0);
		count[MOUSE_4].update((mouse_input & MOUSE_INPUT_4) != 0);
		count[MOUSE_5].update((mouse_input & MOUSE_INPUT_5) != 0);
		count[MOUSE_6].update((mouse_input & MOUSE_INPUT_6) != 0);
		count[MOUSE_7].update((mouse_input & MOUSE_INPUT_7) != 0);
		count[MOUSE_8].update((mouse_input & MOUSE_INPUT_8) != 0);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		count[MOUSE_LEFT].update(s3d::MouseL.pressed() != 0);
		count[MOUSE_RIGHT].update(s3d::MouseR.pressed() != 0);
		count[MOUSE_MIDDLE].update(s3d::MouseM.pressed() != 0);
		count[MOUSE_4].update(s3d::MouseX1.pressed() != 0);
		count[MOUSE_5].update(s3d::MouseX2.pressed() != 0);
		count[MOUSE_6].update(s3d::MouseX3.pressed() != 0);
		count[MOUSE_7].update(s3d::MouseX4.pressed() != 0);
		count[MOUSE_8].update(s3d::MouseX5.pressed() != 0);
#elif defined(ASLIB_INCLUDE_OF)
		for (size_t i = 0; i < mouse_button_num; ++i) {
			count[i].update(asMouseButtonSave(false)[i]);
		}
#elif defined(ASLIB_INCLUDE_TP)

#else //Console

#endif
	}

	inline Counter* const mouseButton()
	{
		static Counter count[mouse_button_num];
		mouseButton(count);
		return count;
	}

	class Mouse 
	{
	public:
		Pos2 Pos() const { return this->pos; };
		int32_t Wheel() const { return this->wheel; };
		Counter Count(const size_t count_num) const { return this->counter[count_num]; };

		Mouse& update();
		bool down() const { return this->counter[MOUSE_LEFT].Down(); };
		bool up() const { return this->counter[MOUSE_LEFT].Up(); };
		int32_t count() const { return this->counter[MOUSE_LEFT].Count(); };

		Mouse() :pos(mousePos()), wheel(mouseWheel()), counter(mouseButton()) {}
		
	private:
		Pos2 pos;
		int32_t wheel;
		
		Counter* const counter;
	};

	inline Mouse& Mouse::update()
	{
		this->pos = mousePos();
		this->wheel = mouseWheel();
		mouseButton(this->counter);
		return *this;
	}

}
