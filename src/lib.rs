#[macro_use]
extern crate num_derive;
extern crate gskrm_sys;
pub mod error;
pub type HINSGSKRM = gskrm_sys::HINSGSKRM;

use std::{ffi::CString, net::Ipv4Addr, os::raw::c_uint};

use error::{Error, Kind, Result, HANDLE_NOTEXIST};

#[derive(FromPrimitive, ToPrimitive)]
pub enum ConnectState {
    InvalidInst = -1,
    Disconnected = 0,
    Connected = 1,
}

#[derive(Debug, FromPrimitive, ToPrimitive)]
pub enum WorkMode {
    Edit,
    Mem,
    Mdi,
    Dnc,
    Jog,
    Handle,
    Ref,
}

#[derive(Debug, FromPrimitive, ToPrimitive)]
pub enum RunState {
    Reset,
    Stop,
    Run,
    Hold,
}

#[derive(Debug, FromPrimitive, ToPrimitive)]
pub enum CoordType {
    Abs,
    Rel,
    Mac,
    Rem,
}

pub fn gsk_create_instance(ip: Ipv4Addr) -> Option<HINSGSKRM> {
    let mut ip = ip.octets();

    // println!("ip is {:?}", ip);
    let ip = ip.as_mut_ptr();
    // println!("ip pointer is {:?}", ip);

    unsafe {
        let handle = gskrm_sys::GSKRM_CreateInstance(ip, 1);
        // println!("handle is {:?}", handle);
        match handle.is_null() {
            true => None,
            false => Some(handle),
        }
    }
}

pub fn gsk_close_instance(handle: Option<HINSGSKRM>) {
    unsafe { gskrm_sys::GSKRM_CloseInstance(handle.expect(HANDLE_NOTEXIST)) }
}

pub fn gsk_get_cnc_typename(handle: Option<HINSGSKRM>) -> Result<String> {
    let type_name = CString::new("").unwrap().into_raw();
    unsafe {
        // let res = gsk_dll::GSKRM_GetCncTypeName(handle.expect(HANDLE_NOTEXIST), type_name);
        let res = gskrm_sys::GSKRM_GetCncTypeName(handle.unwrap(), type_name);
        match res {
            0 => Ok(CString::from_raw(type_name).into_string().unwrap()),
            err_index => Err(Error::new(
                Kind::Communication,
                Some("获取数控类型异常"),
                Some(err_index),
            )),
        }
    }
}

pub fn gsk_get_connect_state(handle: Option<HINSGSKRM>) -> Result<ConnectState> {
    let state = unsafe { gskrm_sys::GSKRM_GetConnectState(handle.expect(HANDLE_NOTEXIST)) };
    match num::FromPrimitive::from_i32(state) {
        Some(state) => Ok(state),
        None => Err(Error::new(
            Kind::Communication,
            Some("获取连接状态异常"),
            None,
        )),
    }
}

pub fn gsk_get_workmode(handle: Option<HINSGSKRM>) -> Result<WorkMode> {
    let work_mode = &mut 0;
    unsafe {
        // let work_mode = libc::malloc(mem::size_of::<u32>()) as *mut u32; // c like
        // let res = gsk_dll::GSKRM_GetWorkMode(handle.expect(HANDLE_NOTEXIST), work_mode);
        let res = gskrm_sys::GSKRM_GetWorkMode(handle.unwrap(), work_mode);
        // println!("gsk work mode res :{},handle:{:?}", res, handle.unwrap());
        match res {
            // 0 => Ok(num::FromPrimitive::from_u32(*work_mode.as_ref().unwrap()).unwrap()),// c like
            0 => Ok(num::FromPrimitive::from_u32(*work_mode).unwrap()),
            err_index => Err(Error::new(
                Kind::Processing,
                Some("获取工作模式异常"),
                Some(err_index),
            )),
        }
    }
}

pub fn gsk_get_cncstate(handle: Option<HINSGSKRM>) -> Result<RunState> {
    let run_state = 0 as *mut c_uint;
    unsafe {
        let res = gskrm_sys::GSKRM_GetCncState(handle.expect(HANDLE_NOTEXIST), run_state);
        match res {
            0 => Ok(num::FromPrimitive::from_u32(*run_state.as_ref().unwrap()).unwrap()),
            err_index => Err(Error::new(
                Kind::Processing,
                Some("获取当前运动状态异常"),
                Some(err_index),
            )),
        }
    }
}

#[cfg(test)]
mod tests {
    use std::net::Ipv4Addr;

    use crate::gsk_create_instance;

    #[test]
    fn get_instance() {
        let ip = "192.168.10.123";
        let ip = ip.parse::<Ipv4Addr>().expect("ip convert error");
        let handle = gsk_create_instance(ip);
        assert!(handle.is_some())
    }
}
