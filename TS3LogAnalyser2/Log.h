#pragma once
//singletonowy log
class Log {
#pragma region singleton
private:
	Log();
public:
	Log(const Log&) = delete;
	Log& operator=(const Log&) = delete;
	Log(Log&&) = delete;
	Log& operator=(Log&&) = delete;

	static Log& getInstance() {
		static Log instance;
		return instance;
	}
private:
#pragma endregion

};

