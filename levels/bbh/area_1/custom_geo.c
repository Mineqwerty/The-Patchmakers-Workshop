//goes before bbh geo area 1
                    GEO_OPEN_NODE(),

						GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -3339, bbh_dl_aareabg_mesh_layer_1),
						GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -3339, bbh_dl_areapatch1_mesh_layer_1),
						GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -3339, bbh_dl_areapatch2_mesh_layer_1),
						GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -3339, bbh_dl_areapatch3_mesh_layer_1),
						GEO_ASM(0, geo_zbuffer_clear),
						//GEO_ASM(0, geo_scale_portal),
						GEO_TRANSLATE_ROTATE_WITH_DL(LAYER_FORCE, 16, 1149, 12839, -90, 0, -180, bbh_dl_Plane_004_mesh_layer_0),
					GEO_CLOSE_NODE(),
					GEO_BRANCH(1, bbh_area_1_geo),