/*
 * This file was generated by the CommonAPI Generators.
 * Used org.genivi.commonapi.someip 3.2.14.v202310241606.
 * Used org.franca.core 0.13.1.201807231814.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 */
#ifndef V1_COMMONAPI_SPEED_SOMEIP_STUB_ADAPTER_HPP_
#define V1_COMMONAPI_SPEED_SOMEIP_STUB_ADAPTER_HPP_

#include <v1/commonapi/speedStub.hpp>

#if !defined (COMMONAPI_INTERNAL_COMPILATION)
#define COMMONAPI_INTERNAL_COMPILATION
#define HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

#include <CommonAPI/SomeIP/AddressTranslator.hpp>
#include <CommonAPI/SomeIP/StubAdapterHelper.hpp>
#include <CommonAPI/SomeIP/StubAdapter.hpp>
#include <CommonAPI/SomeIP/Factory.hpp>
#include <CommonAPI/SomeIP/Types.hpp>
#include <CommonAPI/SomeIP/Constants.hpp>

#if defined (HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE)
#undef COMMONAPI_INTERNAL_COMPILATION
#undef HAS_DEFINED_COMMONAPI_INTERNAL_COMPILATION_HERE
#endif

namespace v1 {
namespace commonapi {

template <typename _Stub = ::v1::commonapi::speedStub, typename... _Stubs>
class speedSomeIPStubAdapterInternal
    : public virtual speedStubAdapter,
      public CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...>,
      public std::enable_shared_from_this< speedSomeIPStubAdapterInternal<_Stub, _Stubs...>>
{
public:
    typedef CommonAPI::SomeIP::StubAdapterHelper< _Stub, _Stubs...> speedSomeIPStubAdapterHelper;

    ~speedSomeIPStubAdapterInternal() {
        deactivateManagedInstances();
        speedSomeIPStubAdapterHelper::deinit();
    }

    void fireSpeedAttributeChanged(const float &_value);
    
    void deactivateManagedInstances() {}
    
    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::speedStub,
        CommonAPI::Version
    > getspeedInterfaceVersionStubDispatcher;

    CommonAPI::SomeIP::GetAttributeStubDispatcher<
        ::v1::commonapi::speedStub,
        float
    > getSpeedAttributeStubDispatcher;
    
    CommonAPI::SomeIP::SetObservableAttributeStubDispatcher<
        ::v1::commonapi::speedStub,
        float
    > setSpeedAttributeStubDispatcher;
    
    speedSomeIPStubAdapterInternal(
        const CommonAPI::SomeIP::Address &_address,
        const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
        const std::shared_ptr<CommonAPI::StubBase> &_stub):
        CommonAPI::SomeIP::StubAdapter(_address, _connection),
        speedSomeIPStubAdapterHelper(
            _address,
            _connection,
            std::dynamic_pointer_cast< speedStub>(_stub)),
        getspeedInterfaceVersionStubDispatcher(&speedStub::lockInterfaceVersionAttribute, &speedStub::getInterfaceVersion, false, true),
        getSpeedAttributeStubDispatcher(
            &::v1::commonapi::speedStub::lockSpeedAttribute,
            &::v1::commonapi::speedStub::getSpeedAttribute,
            false,
            _stub->hasElement(0)),
        setSpeedAttributeStubDispatcher(
            &::v1::commonapi::speedStub::lockSpeedAttribute,
            &::v1::commonapi::speedStub::getSpeedAttribute,
            &speedStubRemoteEvent::onRemoteSetSpeedAttribute,
            &speedStubRemoteEvent::onRemoteSpeedAttributeChanged,
            &speedStubAdapter::fireSpeedAttributeChanged,
            false,
            _stub->hasElement(0))
    {
        speedSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0xfa0) }, &getSpeedAttributeStubDispatcher );
        speedSomeIPStubAdapterHelper::addStubDispatcher( { CommonAPI::SomeIP::method_id_t(0xfa1) }, &setSpeedAttributeStubDispatcher );
        std::shared_ptr<CommonAPI::SomeIP::ClientId> itsClient = std::make_shared<CommonAPI::SomeIP::ClientId>();

        // Provided events/fields
        if (_stub->hasElement(0)) {
            std::set<CommonAPI::SomeIP::eventgroup_id_t> itsEventGroups;
            itsEventGroups.insert(CommonAPI::SomeIP::eventgroup_id_t(CommonAPI::SomeIP::eventgroup_id_t(0x8110)));
            CommonAPI::SomeIP::StubAdapter::registerEvent(CommonAPI::SomeIP::event_id_t(0x8110), itsEventGroups, CommonAPI::SomeIP::event_type_e::ET_FIELD, CommonAPI::SomeIP::reliability_type_e::RT_RELIABLE);
            fireSpeedAttributeChanged(std::dynamic_pointer_cast< ::v1::commonapi::speedStub>(_stub)->getSpeedAttribute(itsClient));
        }

    }

    // Register/Unregister event handlers for selective broadcasts
    void registerSelectiveEventHandlers();
    void unregisterSelectiveEventHandlers();

};

template <typename _Stub, typename... _Stubs>
void speedSomeIPStubAdapterInternal<_Stub, _Stubs...>::fireSpeedAttributeChanged(const float &_value) {
    CommonAPI::SomeIP::StubEventHelper<
        CommonAPI::SomeIP::SerializableArguments<
            float
            >
    >::sendEvent(
        *this,
        CommonAPI::SomeIP::event_id_t(0x8110),
        false,
        _value
    );
}


template <typename _Stub, typename... _Stubs>
void speedSomeIPStubAdapterInternal<_Stub, _Stubs...>::registerSelectiveEventHandlers() {

}

template <typename _Stub, typename... _Stubs>
void speedSomeIPStubAdapterInternal<_Stub, _Stubs...>::unregisterSelectiveEventHandlers() {

}

template <typename _Stub = ::v1::commonapi::speedStub, typename... _Stubs>
class speedSomeIPStubAdapter
    : public speedSomeIPStubAdapterInternal<_Stub, _Stubs...> {
public:
    speedSomeIPStubAdapter(const CommonAPI::SomeIP::Address &_address,
                                            const std::shared_ptr<CommonAPI::SomeIP::ProxyConnection> &_connection,
                                            const std::shared_ptr<CommonAPI::StubBase> &_stub)
        : CommonAPI::SomeIP::StubAdapter(_address, _connection),
          speedSomeIPStubAdapterInternal<_Stub, _Stubs...>(_address, _connection, _stub) {
    }
};

} // namespace commonapi
} // namespace v1

#endif // V1_COMMONAPI_speed_SOMEIP_STUB_ADAPTER_HPP_