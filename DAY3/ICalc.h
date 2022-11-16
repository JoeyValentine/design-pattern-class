// ICalc.h
#pragma once

// 객체의 수명관리를 참조계수로 하기로 했다면
// 참조 계수 함수는 인터페이스도 제공되어야 합니다.

// 수명관리는 모든 종류의 서버의 Proxy 에 항상 필요 합니다.
// 별도의 인터페이스로 제공

struct IRefCount
{
	virtual void AddRef() = 0;
	virtual void Release() = 0;

	virtual ~IRefCount() {}
};

struct ICalc : public IRefCount
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};
