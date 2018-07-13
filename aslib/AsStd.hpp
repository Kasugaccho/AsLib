//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{
#if defined(ASLIB_INCLUDE_S3) //Siv3D
	template<typename... Rest>
	std::string printString(const char *FormatString, const Rest&... rest)
	{

		constexpr int32_t PRINT_STRING_MAX = 1024;
		char snString[PRINT_STRING_MAX];
		snprintf(snString, sizeof(snString), FormatString, rest...);
		return std::string(snString);
	}
#endif

	//ウィンドウサイズを記録する関数
	const Pos2 asWindowSizeSave(const bool b_, const Pos2& p_ = pos2_0)
	{
		static Pos2 p;
		if (b_) p = p_;
		return p;
	}

	//ウィンドウサイズを取得する関数
	inline const Pos2 asWindowSize()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return asWindowSizeSave(false);
#elif defined(ASLIB_INCLUDE_S3)
		return Pos2(s3d::Window::Width(), s3d::Window::Height());
#elif defined(ASLIB_INCLUDE_OF)
		return Pos2();
#elif defined(ASLIB_INCLUDE_TP)
		return Pos2();
#else //Console
		return Pos2();
#endif
	}
	//ウィンドウサイズを取得する関数(float)
	inline const Pos2F asWindowSizeF() { return Pos2F(asWindowSize()); }

	//画面サイズ変更
	inline void asSetWindowSize(const Pos2& window_size = WINDOW_SIZE)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		asWindowSizeSave(true, window_size);
		DxLib::SetGraphMode(window_size.x, window_size.y, 32);
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::Resize(window_size.x, window_size.y);
#elif defined(ASLIB_INCLUDE_OF)
#elif defined(ASLIB_INCLUDE_TP)
		window_size(0);
#else //Console
		window_size(0);
#endif
	}

	//背景色変更
	inline const int32_t asSetBackGround(const ColorRGB& BG_color = BG_COLOR)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::SetBackgroundColor(BG_color.r, BG_color.g, BG_color.b));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Graphics::SetBackground(s3d::Color(BG_color));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		ofBackground(int(BG_color.r), int(BG_color.g), int(BG_color.b));
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}




	//タイトルを記録する関数
	const char* const asTitleSave(const bool b_, const char* const str_ = nullptr)
	{
		static std::string str;
		if (b_ && str_ != nullptr) str = str_;
		return str.c_str();
	}
	//タイトルを取得する関数
	inline const char* const asTitle() { return asTitleSave(false); }

	//タイトル変更
	inline const int32_t asSetTitle(const char* const title)
	{
		asTitleSave(true, title);
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return int32_t(DxLib::SetMainWindowText(title));
#else
		return 0;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::SetTitle(s3d::Unicode::UTF8ToUTF32(title));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		ofSetWindowTitle(title);
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}
	//タイトル変更
	inline const int32_t asSetTitle(const std::string& title)
	{
		return asSetTitle(title.c_str());
	}

	inline const Pos2 asWindowSizeMain(const Pos2& pos2 = pos2_100)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return pos2;
#elif defined(__ANDROID__)
		Pos2 pos;
		pos(-1, -1);
		return pos;
#endif
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	const Pos2 asWindowSizeTrue(const Pos2& pos2 = pos2_100)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		if (pos2.x != -1 || pos2.y != -1) return pos2;
		RECT rc;
		GetWindowRect(GetDesktopWindow(), &rc);
		Pos2 full_pos;
		full_pos(int32_t(rc.right - rc.left), int32_t(rc.bottom - rc.top));
		return full_pos;
#elif defined(__ANDROID__)
		int window_x;
		int window_y;

		if (pos2.x != -1 || pos2.y != -1) return pos2;
		if (DxLib::GetAndroidDisplayResolution(&window_x, &window_y) == -1) return pos2;

		Pos2 pos;
		pos(int32_t(window_x), int32_t(window_y));

		return pos;
#endif
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return pos2;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	const bool is_asFullScreenSize(const Pos2& pos2)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (pos2.x == -1 || pos2.y == -1) return true;
		else return false;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}

	inline const Pos2 asFullScreenSize()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return { -1,-1 };
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}


	inline const Pos2 asSP_FullScreenSize(const Pos2& pos2 = pos2_100)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
#if defined(__WINDOWS__)
		return pos2;
#elif defined(__ANDROID__)
		//int window_x;
		//int window_y;
		//if (DxLib::GetAndroidDisplayResolution(&window_x, &window_y) == -1) return pos2;

		//Pos2 pos;
		//pos(int32_t(window_x), int32_t(window_y));

		return { -1,-1 };
#endif
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
	return 0;
#else //Console
	return 0;
#endif
	}


	const int32_t makeLog(const char* const str_)
	{
		//タイトルのサイズ
		constexpr size_t aslib_title_size = 256;
		char title_str[aslib_title_size];

		asWrite(str_, u8"<!DOCTYPE html><html lang=\"en\"><head><meta charset=\"UTF-8\"/>");
		snprintf(title_str, aslib_title_size, u8"<title>%s</title>", asTitle());
		asAddWrite(str_, title_str);
		asAddWrite(str_, u8"<style>body{background-color:#f9f9f9;font-family:'SegoeUI','メイリオ','Meiryo','ヒラギノ角ゴProW3','HiraginoKakuGothicPro','Osaka','ＭＳＰゴシック','MSPGothic','Arial',sans-serif;}h2{color:#333333;text-align:center;font-size:28px;}h3{color:#333333;text-align:center;font-size:24px;}main{font-size:14px;line-height:2;word-wrap:break-word;}main.name{color:#333333;text-align:center;font-size:20px;}main.copyright{padding-bottom:8px;color:#555555;text-align:center;font-size:12px;}main.license{padding-bottom:24px;color:#888888;text-align:center;font-size:9px;}</style></head><body>");
		snprintf(title_str, aslib_title_size, u8"<h2>%s</h2><br><h3>Licenses</h3>", asTitle());
		asAddWrite(str_, title_str);

		std::string license_name = u8"";
		std::vector<Copyright> license_copyright;
		std::string license_str = u8"";
		for (size_t i = 0; i < aslib_license_size; ++i) {
			license_copyright.clear();
			asLicense(aslib_license[i], license_name, license_copyright, license_str);

			asAddWrite(str_, u8"<main class=\"name\">");
			asAddWrite(str_, license_name.c_str());
			asAddWrite(str_, u8"</main>");

			for (size_t j = 0; j < license_copyright.size(); ++j) {
				asAddWrite(str_, u8"<main class=\"copyright\">");
				asAddWrite(str_, license_copyright[j].write());
				asAddWrite(str_, u8"</main>");
			}

			asAddWrite(str_, u8"<main class=\"license\">");
			asAddWrite(str_, license_str.c_str());
			asAddWrite(str_, u8"</main>");
		}

		asAddWrite(str_, u8"</body></html>");
		return 0;
	}

	const int32_t makeLog() {
		char str[256];
		snprintf(str, 256, u8"%s_Licenses.html", asTitle());
		return makeLog(str);
	}


	//初期化
	const int32_t AsInit(const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		if (DxLib::SetOutApplicationLogValidFlag(FALSE) == -1) return -1;
		if (DxLib::SetChangeScreenModeGraphicsSystemResetFlag(FALSE) == -1) return -1;
#if defined(__WINDOWS__)
		DxLib::SetWindowIconID(22);
		DxLib::SetWindowSizeChangeEnableFlag(TRUE);
		if (DxLib::SetUseCharCodeFormat(DX_CHARCODEFORMAT_UTF8) == -1) return -1;

		//フルスクリーンモード
		if (is_asFullScreenSize(window_size)) {
			DxLib::SetFullScreenResolutionMode(DX_FSRESOLUTIONMODE_NATIVE);
			if (DxLib::ChangeWindowMode(FALSE) == -1) return -1;
			RECT rc;
			GetWindowRect(GetDesktopWindow(), &rc);
			Pos2 full_pos;
			full_pos(int32_t(rc.right - rc.left), int32_t(rc.bottom - rc.top));
			asSetWindowSize(full_pos);
		}
		else {//通常のモード
			if (DxLib::ChangeWindowMode(TRUE) == -1) return -1;
			asSetWindowSize(window_size);
		}
#endif
		if (asSetBackGround(BG_color) == -1) return -1;
		//ここで初期化
		if (DxLib::DxLib_Init() == -1) return -1;

#if defined(__WINDOWS__)
		//フルスクリーンモード
		if (is_asFullScreenSize(window_size)) {
			//マウスの表示をON
			DxLib::SetMouseDispFlag(TRUE);
		}
#endif
#if defined(__ANDROID__)
		if (asSetWindowSize(asWindowSizeTrue(window_size)) == -1) return -1;
#endif
		if (DxLib::SetDXArchiveExtension("as") == -1) return -1;

		if (DxLib::SetDrawScreen(DX_SCREEN_BACK)) return -1;

		if (DxLib::SetFontSize(20) == -1) return -1;
		//DX_FONTTYPE_ANTIALIASING_EDGE//DX_FONTTYPE_NORMAL
		if (DxLib::ChangeFontType(DX_FONTTYPE_ANTIALIASING_EDGE_8X8) == -1) return -1;
#if defined(__WINDOWS__)
		if (DxLib::SetKeyInputStringColor(
			0xff000000, 0xff000000,
			0xffffffff, 0xff000000,
			0xff000000, 0xffcde8ff,
			0xff000000, 0xffffffff,
			0xff9f9f9f, 0xffffffff,
			0xffa0a0a0, 0xffffffff,
			0xffadd6ff, 0xff000000,
			0xffffffff, 0xff000000,
			0xffffffff) == -1) return -1;

		DxLib::SetUseDirectInputFlag(TRUE);
#endif
		if (DxLib::SetUseASyncLoadFlag(FALSE) == -1) return -1;
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Window::Resize(window_size.x, window_size.y);
		s3d::Graphics::SetBackground(s3d::Color(BG_color));
		static s3d::RenderStateBlock2D wireframe(s3d::SamplerState::ClampNearest);
#elif defined(ASLIB_INCLUDE_OF)
		//asSetWindowSize(window_size);
		asSetBackGround(BG_color);
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif

#if !defined(ASLIB_DONOT_USE_LOG)
makeLog();
#endif
return 0;
	}

	//終了処理
	inline const int32_t asEnd()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::DxLib_End());
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}

	//文字出力
	template<typename... Rest>
	inline const int32_t asPrint(const char* const format_string, const Rest&... rest)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::printfDx(format_string, rest...));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Print(s3d::Unicode::UTF8ToUTF32(printString(format_string, rest...)));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)

#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}
	inline const int32_t asPrint(const char* const format_string)
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		return int32_t(DxLib::printfDx("%s", format_string));
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
		s3d::Print(s3d::Unicode::UTF8ToUTF32(format_string));
		return 0;
#elif defined(ASLIB_INCLUDE_OF)
		return 0;
#elif defined(ASLIB_INCLUDE_TP)
return 0;
#else //Console
return 0;
#endif
	}

//以降は他ライブラリ依存なし----------

	const int32_t AsInit(const char* const title = u8"", const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (asSetTitle(title) == -1) return -1;
		return AsInit(window_size, BG_color);
	}

	const int32_t AsInit(const std::string& title = u8"", const Pos2& window_size = WINDOW_SIZE, const ColorRGB& BG_color = BG_COLOR)
	{
		if (asSetTitle(title.c_str()) == -1) return -1;
		return AsInit(window_size, BG_color);
	}

	template<typename... Rest>
	inline const int32_t asPrint(const std::string& format_string, const Rest&... rest)
	{
		return asPrint(format_string.c_str(), rest...);
	}

	inline const int32_t asPrint(const std::string& format_string)
	{
		return asPrint(format_string.c_str());
	}



}