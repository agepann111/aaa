// ウィンドウアプリケーション

#include "../window/window.h"

#include <cassert>

namespace {
constexpr std::string_view APP_NAME = "MyApp";  /// アプリケーション名
}  // namespace

class Application final {
public:
    //---------------------------------------------------------------------------------
    /**
     * @brief    コンストラクタ
     */
    Application() = default;

    //---------------------------------------------------------------------------------
    /**
     * @brief    デストラクタ
     */
    ~Application() = default;

    //---------------------------------------------------------------------------------
    /**
     * @brief	アプリケーションの初期化
     * @return	初期化の成否
     */
    [[nodiscard]] HRESULT initialize(HINSTANCE instance) noexcept {
        // ウィンドウの生成
        return windowInstance_.create(instance, 1280, 720, APP_NAME);
    }

    //---------------------------------------------------------------------------------
    /**
     * @brief	アプリケーションループ
     */
    void loop() noexcept {
        while (windowInstance_.messageLoop()) {
            // メッセージループ内での処理をここに記述
        }

        // ループを抜けるとウィンドウを閉じる
    }

private:
    Window windowInstance_;  /// ウィンドウインスタンス
};

//---------------------------------------------------------------------------------
/**
 * @brief	エントリー関数
 */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

	// アプリケーションクラスのインスタンスを生成
    Application app;

    if (app.initialize(hInstance)) {
        assert(false && "ウィンドウの初期化に失敗しました");
    }

	// アプリケーションループを開始
    app.loop();

    return 0;
}
