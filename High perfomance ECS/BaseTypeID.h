#ifndef _BASETYPEID_H_
#define _BASETYPEID_H_

#include <iostream>
using namespace std;

namespace ECS
{
	/* Counting Component or System */

	template<typename Base>
	class TypeId
	{
	public:

		template<typename T>
		static const size_t get()
		{
			static_assert(std::is_base_of<Base, T>::value, "T is not inherit from Base");

			static size_t id = count();

			return id;
		}

		static size_t count()
		{
			static size_t lastId{ 0u };

			return lastId++;
		}
	};

}





#endif