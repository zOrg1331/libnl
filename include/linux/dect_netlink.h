#ifndef _LINUX_DECT_NETLINK_H
#define _LINUX_DECT_NETLINK_H

struct dectmsg {
	int	dm_index;
};

enum dect_nlgroups {
	DECTNLGRP_NONE,
	DECTNLGRP_TRANSCEIVER,
	DECTNLGRP_CELL,
	DECTNLGRP_CLUSTER,
	DECTNLGRP_LLME,
	__DECTNLGRP_MAX
};
#define DECTNLGRP_MAX		(__DECTNLGRP_MAX - 1)

enum dect_netlink_msg_types {
	DECT_MSG_BASE = 0x10,
	DECT_NEW_TRANSCEIVER,
	DECT_DEL_TRANSCEIVER,
	DECT_GET_TRANSCEIVER,
	DECT_NEW_CELL,
	DECT_DEL_CELL,
	DECT_GET_CELL,
	DECT_NEW_CLUSTER,
	DECT_DEL_CLUSTER,
	DECT_GET_CLUSTER,
	DECT_LLME_MSG,
	__DECT_MSG_MAX
};
#define DECT_MSG_MAX		(__DECT_MSG_MAX - 1)

#define DECT_NR_MSGTYPES	(DECT_MSG_MAX + 1 - DECT_MSG_BASE)

enum dect_list_attrs {
	DECTA_LIST_UNSPEC,
	DECTA_LIST_ELEM,
	__DECTA_LIST_MAX
};
#define DECTA_LIST_MAX		(__DECTA_LIST_MAX - 1)

enum dect_slot_states {
	DECT_SLOT_IDLE,
	DECT_SLOT_SCANNING,
	DECT_SLOT_RX,
	DECT_SLOT_TX,
};

enum dect_slot_flags {
	DECT_SLOT_SYNC			= 0x1,
	DECT_SLOT_CIPHER		= 0x2,
};

#define DECT_PHASE_OFFSET_SCALE		1024

enum dect_slot_attrs {
	DECTA_SLOT_UNSPEC,
	DECTA_SLOT_NUM,
	DECTA_SLOT_STATE,
	DECTA_SLOT_FLAGS,
	DECTA_SLOT_CARRIER,
	DECTA_SLOT_FREQUENCY,
	DECTA_SLOT_PHASEOFF,
	DECTA_SLOT_RSSI,
	DECTA_SLOT_RX_PACKETS,
	DECTA_SLOT_RX_BYTES,
	DECTA_SLOT_RX_A_CRC_ERRORS,
	DECTA_SLOT_RX_X_CRC_ERRORS,
	DECTA_SLOT_RX_Z_CRC_ERRORS,
	DECTA_SLOT_TX_PACKETS,
	DECTA_SLOT_TX_BYTES,
	__DECTA_SLOT_MAX
};
#define DECTA_SLOT_MAX			(__DECTA_SLOT_MAX - 1)

enum dect_transceiver_stats_attrs {
	DECTA_TRANSCEIVER_STATS_UNSPEC,
	DECTA_TRANSCEIVER_STATS_EVENT_BUSY,
	DECTA_TRANSCEIVER_STATS_EVENT_LATE,
	__DECTA_TRANSCEIVER_STATS_MAX
};
#define DECTA_TRANSCEIVER_STATS_MAX	(__DECTA_TRANSCEIVER_STATS_MAX - 1)

enum dect_transceiver_attrs {
	DECTA_TRANSCEIVER_UNSPEC,
	DECTA_TRANSCEIVER_NAME,
	DECTA_TRANSCEIVER_TYPE,
	DECTA_TRANSCEIVER_LINK,
	DECTA_TRANSCEIVER_STATS,
	DECTA_TRANSCEIVER_BAND,
	DECTA_TRANSCEIVER_SLOTS,
	__DECTA_TRANSCEIVER_MAX
};
#define DECTA_TRANSCEIVER_MAX		(__DECTA_TRANSCEIVER_MAX - 1)

enum dect_cell_flags {
	DECT_CELL_CCP		= (1 << 0),
	DECT_CELL_SLAVE		= (1 << 1),
	DECT_CELL_MONITOR	= (1 << 2),
};

enum dect_cell_attrs {
	DECTA_CELL_UNSPEC,
	DECTA_CELL_NAME,
	DECTA_CELL_FLAGS,
	DECTA_CELL_TRANSCEIVERS,
	DECTA_CELL_CLUSTER,
	__DECTA_CELL_MAX
};
#define DECTA_CELL_MAX		(__DECTA_CELL_MAX - 1)

enum dect_cluster_attrs {
	DECTA_CLUSTER_UNSPEC,
	DECTA_CLUSTER_NAME,
	DECTA_CLUSTER_MODE,
	DECTA_CLUSTER_PARI,
	DECTA_CLUSTER_CELLS,
	__DECTA_CLUSTER_MAX
};
#define DECTA_CLUSTER_MAX	(__DECTA_CLUSTER_MAX - 1)

enum dect_cluster_modes {
	DECT_MODE_FP,
	DECT_MODE_PP,
};

/**
 * DECT ARI classes
 *
 * @DECT_ARC_A:	Residential and private (PBX) single- and small multiple cell systems
 * @DECT_ARC_B:	Private (PABXs) multiple cell
 * @DECT_ARC_C: Public single and multiple cell systems
 * @DECT_ARC_D: Public DECT access to a GSM network
 * @DECT_ARC_E: PP to PP direct communication (private)
 */
enum dect_ari_classes {
	DECT_ARC_A,
	DECT_ARC_B,
	DECT_ARC_C,
	DECT_ARC_D,
	DECT_ARC_E,
};

enum dect_ari_attrs {
	DECTA_ARI_UNSPEC,
	DECTA_ARI_CLASS,
	DECTA_ARI_FPN,
	DECTA_ARI_FPS,
	DECTA_ARI_EMC,
	DECTA_ARI_EIC,
	DECTA_ARI_POC,
	DECTA_ARI_GOP,
	DECTA_ARI_FIL,
	__DECTA_ARI_MAX
};
#define DECTA_ARI_MAX		(__DECTA_ARI_MAX - 1)

enum decta_sari_attrs {
	DECTA_SARI_UNSPEC,
	DECTA_SARI_ARI,
	DECTA_SARI_BLACK,
	DECTA_SARI_TARI,
	__DECTA_SARI_MAX
};
#define DECTA_SARI_MAX		(__DECTA_SARI_MAX - 1)

enum dect_fixed_part_capabilities {
	DECT_FPC_EXTENDED_FP_INFO		= 0x80000,
	DECT_FPC_DOUBLE_DUPLEX_BEARER_CONNECTION= 0x40000,
	DECT_FPC_RESERVED			= 0x20000,
	DECT_FPC_DOUBLE_SLOT			= 0x10000,
	DECT_FPC_HALF_SLOT			= 0x08000,
	DECT_FPC_FULL_SLOT			= 0x04000,
	DECT_FPC_FREQ_CONTROL			= 0x02000,
	DECT_FPC_PAGE_REPETITION		= 0x01000,
	DECT_FPC_CO_SETUP_ON_DUMMY		= 0x00800,
	DECT_FPC_CL_UPLINK			= 0x00400,
	DECT_FPC_CL_DOWNLINK			= 0x00200,
	DECT_FPC_BASIC_A_FIELD_SETUP		= 0x00100,
	DECT_FPC_ADV_A_FIELD_SETUP		= 0x00080,
	DECT_FPC_B_FIELD_SETUP			= 0x00040,
	DECT_FPC_CF_MESSAGES			= 0x00020,
	DECT_FPC_IN_MIN_DELAY			= 0x00010,
	DECT_FPC_IN_NORM_DELAY			= 0x00008,
	DECT_FPC_IP_ERROR_DETECTION		= 0x00004,
	DECT_FPC_IP_ERROR_CORRECTION		= 0x00002,
	DECT_FPC_MULTIBEARER_CONNECTIONS	= 0x00001,
};

enum dect_higher_layer_capabilities {
	DECT_HLC_ADPCM_G721_VOICE		= 0x8000,
	DECT_HLC_GAP_PAP_BASIC_SPEECH		= 0x4000,
	DECT_HLC_NON_VOICE_CIRCUIT_SWITCHED	= 0x2000,
	DECT_HLC_NON_VOICE_PACKET_SWITCHED	= 0x1000,
	DECT_HLC_STANDARD_AUTHENTICATION	= 0x0800,
	DECT_HLC_STANDARD_CIPHERING		= 0x0400,
	DECT_HLC_LOCATION_REGISTRATION		= 0x0200,
	DECT_HLC_SIM_SERVICES			= 0x0100,
	DECT_HLC_NON_STATIC_FIXED_PART		= 0x0080,
	DECT_HLC_CISS_SERVICE			= 0x0040,
	DECT_HLC_CLMS_SERVICE			= 0x0020,
	DECT_HLC_COMS_SERVICE			= 0x0010,
	DECT_HLC_ACCESS_RIGHTS_REQUESTS		= 0x0008,
	DECT_HLC_EXTERNAL_HANDOVER		= 0x0004,
	DECT_HLC_CONNECTION_HANDOVER		= 0x0002,
	DECT_HLC_RESERVED			= 0x0001,
};

enum dect_extended_fixed_part_capabilities {
	DECT_EFPC_WRS_MASK			= 0x1f80,
	DECT_EFPC_WRS_CRFP_HOPS_MASK		= 0x1800,
	DECT_EFPC_WRS_CRFP_HOPS_1		= 0x0000,
	DECT_EFPC_WRS_CRFP_HOPS_2		= 0x0800,
	DECT_EFPC_WRS_CRFP_HOPS_3		= 0x1000,
	DECT_EFPC_WRS_CRFP_HOPS_NONE		= 0x1800,
	DECT_EFPC_WRS_CRFP_ENCRYPTION		= 0x0400,
	DECT_EFPC_WRS_REP_HOPS_MASK		= 0x0300,
	DECT_EFPC_WRS_REP_HOPS_NONE		= 0x0000,
	DECT_EFPC_WRS_REP_HOPS_1		= 0x0100,
	DECT_EFPC_WRS_REP_HOPS_2		= 0x0200,
	DECT_EFPC_WRS_REP_HOPS_3		= 0x0300,
	DECT_EFPC_WRS_REP_INTERLACING		= 0x0080,
	DECT_EFPC_SYNC_MASK			= 0x0060,
	DECT_EFPC_SYNC_PROLONGED_PREAMBLE	= 0x0020,
	DECT_EFPC_SYNC_RESERVED1		= 0x0010,
	DECT_EFPC_MAC_SUSPEND_RESUME		= 0x0008,
	DECT_EFPC_MAC_IP_Q_SERVICE		= 0x0004,
	DECT_EFPC_EXTENDED_FP_INFO2		= 0x0002,
	DECT_EFPC_RESERVED2			= 0x0001,
};

enum dect_extended_higher_layer_capabilities {
	DECT_EHLC_ISDN_DATA_SERVICE		= 0x000001,
	DECT_EHLC_DPRS_FREL			= 0x000002,
	DECT_EHLC_DPRS_STREAM			= 0x000004,
	DECT_EHLC_DATA_SERVICE_PROFILE_D	= 0x000008,
	DECT_EHLC_LRMS				= 0x000010,
	DECT_EHLC_ASYMETRIC_BEARERS		= 0x000040,
	DECT_EHLC_EMERGENCY_CALLS		= 0x000080,
	DECT_EHLC_TPUI_LOCATION_REGISTRATION	= 0x000100,
	DECT_EHLC_GPS_SYNCHRONIZED		= 0x000200,
	DECT_EHLC_ISDN_INTERMEDIATE_SYSTEM	= 0x000400,
	DECT_EHLC_RAP_PART_1_PROFILE		= 0x000800,
	DECT_EHLC_V_24				= 0x004000,
	DECT_EHLC_PPP				= 0x008000,
	DECT_EHLC_IP				= 0x010000,
	DECT_EHLC_TOKEN_RING			= 0x020000,
	DECT_EHLC_ETHERNET			= 0x040000,
	DECT_EHLC_IP_ROAMING			= 0x080000,
	DECT_EHLC_GENERIC_MEDIA_ENCAPSULATION	= 0x100000,
	DECT_EHLC_BASIC_ODAP			= 0x200000,
	DECT_EHLC_F_MMS_INTERWORKING_PROFILE	= 0x400000,
};

enum dect_extended_fixed_part_capabilities2 {
	DECT_EFPC2_LONG_SLOT_J640		= 0x800,
	DECT_EFPC2_LONG_SLOT_J672		= 0x400,
	DECT_EFPC2_IP_F				= 0x200,
	DECT_EFPC2_SI_PF			= 0x100,
	DECT_EFPC2_GF				= 0x080,
	DECT_EFPC2_NO_EMISSION_CARRIER		= 0x001,
};

enum dect_extended_higher_layer_capabilities2 {
	DECT_EHLC2_NG_DECT_PERMANENT_CLIR	= 0x000100,
	DECT_EHLC2_NG_DECT_MULTIPLE_CALLS	= 0x000200,
	DECT_EHLC2_NG_DECT_MULTIPLE_LINES	= 0x000400,
	DECT_EHLC2_EASY_PAIRING			= 0x000800,
	DECT_EHLC2_LIST_ACCESS_FEATURES		= 0x001000,
	DECT_EHLC2_NO_EMISSION_MODE		= 0x002000,
	DECT_EHLC2_NG_DECT_CALL_DEFLECTION	= 0x004000,
	DECT_EHLC2_NG_DECT_INTRUSION_CALL	= 0x008000,
	DECT_EHLC2_NG_DECT_CONFERENCE_CALL	= 0x010000,
	DECT_EHLC2_NG_DECT_PARALLEL_CALLS	= 0x020000,
	DECT_EHLC2_NG_DECT_CALL_TRANSFER	= 0x040000,
	DECT_EHLC2_NG_DECT_EXTENDED_WIDEBAND	= 0x080000,
	DECT_EHLC2_PACKET_DATA_CATEGORY_MASK	= 0x700000,
	DECT_EHLC2_NG_DECT_WIDEBAND		= 0x800000,
};

enum dect_mac_info_attrs {
	DECTA_MAC_INFO_UNSPEC,
	DECTA_MAC_INFO_PARI,
	DECTA_MAC_INFO_RPN,
	DECTA_MAC_INFO_RSSI,
	DECTA_MAC_INFO_SARI_LIST,
	DECTA_MAC_INFO_FPC,
	DECTA_MAC_INFO_HLC,
	DECTA_MAC_INFO_EFPC,
	DECTA_MAC_INFO_EHLC,
	DECTA_MAC_INFO_EFPC2,
	DECTA_MAC_INFO_EHLC2,
	DECTA_MAC_INFO_MFN,
	__DECTA_MAC_INFO_MAX
};
#define DECTA_MAC_INFO_MAX	(__DECTA_MAC_INFO_MAX - 1)

enum dect_llme_ops {
	DECT_LLME_REQUEST,
	DECT_LLME_INDICATE,
	DECT_LLME_RESPONSE,
	DECT_LLME_CONFIRM,
};

enum dect_llme_msg_types {
	DECT_LLME_SCAN,
	DECT_LLME_MAC_INFO,
	DECT_LLME_MAC_RFP_PRELOAD,
	__DECT_LLME_MAX
};
#define DECT_LLME_MAX		(__DECT_LLME_MAX - 1)

enum dect_llme_msg_attrs {
	DECTA_LLME_UNSPEC,
	DECTA_LLME_OP,
	DECTA_LLME_TYPE,
	DECTA_LLME_DATA,
	__DECTA_LLME_MAX
};
#define DECTA_LLME_MAX		(__DECTA_LLME_MAX - 1)

#endif /* _LINUX_DECT_NETLINK_H */
