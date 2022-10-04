#pragma once
class cObject
{
public:
	cObject();
	virtual ~cObject();

	virtual void AddRef();
	virtual void Release();

protected:
	ULONG m_ulRefCount;

private:
};

