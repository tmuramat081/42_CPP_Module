template <typename T>
class contactRepository : public Repository<T>
{
public:
	void save(const T& item)
	{
		dataSource[item.getId() = item];

	}
	

}