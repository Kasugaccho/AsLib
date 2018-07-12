//     ----------     ----------     ----------     ----------     ----------
//
//                              AsLib - Asライブラリ
//
//                    制作者: がっちょ (wanotaitei@gmail.com)
//
//     ----------     ----------     ----------     ----------     ----------


namespace AsLib
{

	inline void asStop()
	{
#if defined(ASLIB_INCLUDE_DL) //DxLib
		DxLib::ScreenFlip();
		DxLib::WaitKey();
#elif defined(ASLIB_INCLUDE_S3) //Siv3D
#elif defined(ASLIB_INCLUDE_OF)
#elif defined(ASLIB_INCLUDE_TP)
#else //Console
#endif
	}

}
