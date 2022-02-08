#include "Entity.h"

#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Excalibur
{
	Entity::Entity()
		: m_MeshRender(nullptr),
		m_Camera(nullptr),
		m_Transform(nullptr)
	{
		m_Guid = xg::newGuid();
	}

	Entity::Entity(const xg::Guid& guid)
		: m_Parent(nullptr),
		m_Transform(nullptr),
		m_Guid(guid)
	{

	}

	Entity::~Entity()
	{
		std::cout << "destructor of entity: " << m_Guid << std::endl;
	}

	int	Entity::Initialize() noexcept
	{
		return 0;
	}

	int	Entity::Initialize(World* world) noexcept
	{
		m_World = world;

		AddComponent<TransformComponent>();

		return 0;
	}

	void Entity::Finalize() noexcept
	{
		m_Children.clear();
		m_Parent = nullptr;
	}

	xg::Guid Entity::GetGuid() const
	{
		return m_Guid;
	}

	void Entity::SetGuid(const xg::Guid& guid)
	{
		m_Guid = guid;
	}

	void Entity::AddChild(std::shared_ptr<Entity> child)
	{
		if (IsChild(child))
			return;

		m_Children.push_back(child);
		child->SetParent(this);
	}

	void Entity::RemoveChild(std::shared_ptr<Entity> child)
	{
		if (IsChild(child))
			return;

		for (auto iter = m_Children.begin(); iter != m_Children.end(); iter++)
		{
			if ((*iter) == child)
			{
				m_Children.erase(iter);
				child->SetParent(nullptr);
				return;
			}
		}
	}

	Entity* Entity::GetParent()
	{
		return m_Parent;
	}

	void Entity::SetParent(Entity* parent)
	{
		m_Parent = parent;
	}

	bool Entity::IsChild(std::shared_ptr<Entity> child)
	{
		if (child->GetParent() == this)
		{
			return true;
		}
		return false;
	}

	size_t Entity::GetChildrenCount()
	{
		return m_Children.size();
	}
}