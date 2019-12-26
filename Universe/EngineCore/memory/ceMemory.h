#pragma once
#include "precompiled.h"
namespace memory
{
	class MemPageInterface
	{
		virtual void*	GetMemoryFromSystem()=0;
		virtual void	ReleaseSystemMemory(void*)=0;
		virtual bool	IsFromThisMemPageInterface(void*)=0;
	};

	class MemAllocator
	{
		virtual void*	Alloc(size_t size);
		virtual void	Free(void*);
		virtual bool	IsFromThisAllocator(void*);
	};
	//alloc
	class DefaultAllocator
	{
		template<typename T>
		T* Alloc(ce::size size)
		{
			(T*)std::malloc(size);
		}
		//free
		void Free(void* ptr)
		{
			std::free(ptr);
		}

		//memcpy
		template<typename T>
		void memcpy(void* dst, void* src)
		{
			memcpy(dst, src, sizeof(T));
		}

		void memcpy(void* dst, void* src, ce::size size)
		{
			std::memcpy(dst, src, size);
		}
	};

	//memset
	
}

