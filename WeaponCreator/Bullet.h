#ifndef BULLET_H
#define BULLET_H

template<typename T>
class Bullet
{
public:
	using value_type = T;
	using reference = T&;
	using const_reference = const T&;

	template<typename... Args>
	void emplace(Args&&... args) {
		data.emplace_back(std::forward<Args>(args)...);
	}

	template<typename U = T>
	std::enable_if_t<std::is_copy_constructible_v<U>>
		push(const U& value) {
		data.push_back(value);
	}
private:
	std::vector<T> data;
	
};
#endif
