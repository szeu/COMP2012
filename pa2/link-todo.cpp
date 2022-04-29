#include "link.h"

//// TODO: complete the member function defintions of LinkImpl and LinkProxy
LinkImpl::LinkImpl(LinkType link_type, LinkProperties properties) : 
          Link(link_type), properties_(properties){}

bool LinkImpl::IsBuilt() const{
    return adj_ != nullptr;
}

bool LinkImpl::Build(Link* link){
    if(link == nullptr) return false;
    if(CanOverbuild(link)){
        adj_ = link->adjacency();
        link->BeOverbuilt(this);
        return true;
    }
    else{
        return false;
    }
}

bool LinkImpl::CanOverbuild(Link* link) const{
    if(link == nullptr) return true;
    if(link->IsBuilt())
        return false;
    else
        return true;
}

int LinkImpl::vp() const{
    if(adj_ != nullptr)
        return adj_->vp_for_link();
    else
        return 0;
}

LinkProperties LinkImpl::properties() const{
    return properties_;
}

Player* LinkImpl::player() const{
    return player_;
}

std::string LinkImpl::player_name() const{
    if(player_ != nullptr)
        return player_->name();
    else
        return kEmptyPlayerName;
}

void LinkImpl::set_player(Player* player){
    player_ = player;
}

void LinkImpl::set_observer(LinkObserver* observer){}

LinkProxy::LinkProxy(LinkType link_type, Adjacency* adj) : 
           Link(link_type, adj){}

bool LinkProxy::IsBuilt() const{
    return (impl_ != nullptr && (impl_->IsBuilt()));
}

bool LinkProxy::Build(Link* link){
    static_cast<void>(link);
    return false;
}

bool LinkProxy::CanOverbuild(Link* link) const{
    static_cast<void>(link);
    return false;
}

void LinkProxy::BeOverbuilt(Link* link){
    if(impl_ != nullptr) 
        impl_->BeOverbuilt(link);
    impl_ = static_cast<LinkImpl*>(link);
    link->set_observer(observer_);
    impl_->set_adjacency(adj_);
    if(observer_)
        observer_->UpdateLink(this);
}

int LinkProxy::vp() const{
    if(impl_ != nullptr)
        return impl_->vp();
    else return 0;
}

LinkProperties LinkProxy::properties() const{
    if(impl_ != nullptr)
        return impl_->properties();
    else return {};
}

Player* LinkProxy::player() const{
    if(impl_ != nullptr)
        return impl_->player();
    else return nullptr;
}

std::string LinkProxy::player_name() const{
    if (impl_ != nullptr)
        return impl_->player_name();
    else return kEmptyPlayerName;
}

void LinkProxy::set_player(Player* player){
    static_cast<void>(player);
}

void LinkProxy::set_observer(LinkObserver* oberser){
    observer_ = oberser;
    observer_->UpdateLink(this);
}
// TODO ends
