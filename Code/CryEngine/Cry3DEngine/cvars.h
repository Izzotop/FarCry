////////////////////////////////////////////////////////////////////////////
//
//  Crytek Engine Source File.
//  Copyright (C), Crytek Studios, 2002.
// -------------------------------------------------------------------------
//  File name:   cvars.h
//  Version:     v1.00
//  Created:     28/5/2001 by Vladimir Kajalin
//  Compilers:   Visual Studio.NET
//  Description:
// -------------------------------------------------------------------------
//  History:
//
////////////////////////////////////////////////////////////////////////////

#ifndef _3DENGINE_CVARS_H_
#define _3DENGINE_CVARS_H_

// console variables
struct CVars : public Cry3DEngineBase {
    CVars() {
        Init();
    }

    void Init();

    using IntVar = int;
    using FloatVar = float;

    IntVar e_allow_cvars_serialization;
    IntVar e_shadow_maps;
    IntVar e_shadow_maps_debug;
    IntVar e_shadow_maps_from_static_objects;
    IntVar e_shadow_maps_self_shadowing;
    IntVar e_shadow_maps_receiving;
    IntVar e_detail_objects;
    IntVar e_fog;
    IntVar e_motion_blur;
    IntVar e_beach;
    IntVar e_detail_texture;
    IntVar e_detail_texture_quality;
    IntVar e_particles;
    IntVar e_particles_debug;
    IntVar e_particles_max_count;
    IntVar e_particles_receive_shadows;
    IntVar e_decals;
    IntVar e_bflyes;
    IntVar e_vegetation_bending;
    IntVar e_vegetation;
    IntVar e_vegetation_sprites;
    IntVar e_entities;
    IntVar e_entities_debug;
    IntVar e_sky_box;
    IntVar e_terrain;
    IntVar e_terrain_debug;
    IntVar e_water_ocean;
    IntVar e_vegetation_debug;
    IntVar e_shadow_maps_frustums;
    IntVar e_terrain_occlusion_culling;
    IntVar e_terrain_texture_pool;
    IntVar e_terrain_texture_bind;
    IntVar e_terrain_log;
    IntVar e_out_space;
    IntVar e_video_buffer_stats;
    IntVar e_sun;
    IntVar e_terrain_merge_far_sectors;
    IntVar e_terrain_texture_mipmaps;
    IntVar e_terrain_texture_mip_offset;

    // if set to non-0, then after the specified number of frames rendered,
    // the game exits printing the average FPS value.
    // NOTE:
    //  for this to work, the r_DisplayInfo must be "1"
    IntVar e_timedemo_frames;

    // if set to non-0, then after the specified number of milliseconds of rendering,
    // the game exists unconditionally. This is used for automatic multipass profiling with VTune 6.x
    IntVar e_timedemo_milliseconds;

    IntVar e_cbuffer;
    IntVar e_dynamic_light;
    IntVar e_dynamic_light_exact_vis_test;
    IntVar e_stencil_shadows;
    IntVar e_dynamic_light_debug;
    IntVar e_hw_occlusion_culling_water;
    IntVar e_hw_occlusion_culling_objects;
    IntVar e_hires_screenshoot;
    IntVar e_portals;
    IntVar e_max_entity_lights;
    IntVar e_max_shadow_map_size;
    IntVar e_water_volumes;
    IntVar e_bboxes;
    IntVar e_brushes;
    IntVar e_brushes_merging_debug;
    IntVar e_brushes_merging;
    IntVar e_brushes_onlymerged;
    IntVar e_register_in_sectors;
    IntVar e_stream_cgf;
    IntVar e_stream_for_physics;
    IntVar e_stream_for_visuals;
    IntVar e_stream_areas;
    IntVar e_scissor_debug;
    IntVar e_projector_exact_test;
    IntVar e_ccgf_load;
    IntVar e_ccgf_make_if_not_found;
    IntVar e_check_number_of_physicalized_polygons;
    IntVar e_materials;
    IntVar e_vegetation_sprites_slow_switch;
    IntVar e_terrain_single_pass;
    IntVar e_stream_preload_textures;
    IntVar e_area_merging_distance;
    IntVar e_area_merging_draw_merged_geometry_only;
    IntVar e_area_merging_max_tris_in_input_brush;
    IntVar e_on_demand_physics;
    IntVar e_light_maps;
    IntVar e_light_maps_quality;
    IntVar e_light_maps_occlusion;
    IntVar e_sleep;
    IntVar e_objects;
    IntVar e_terrain_draw_this_sector_only;
    IntVar e_sun_stencil;
    IntVar e_terrain_single_pass_vol_fog;
    IntVar e_occlusion_volumes;
    IntVar e_overlay_geometry;
    IntVar e_player;
    IntVar e_vegetation_sprites_texres;
    IntVar e_active_shadow_maps_receving;
    IntVar e_shadow_maps_fade_from_light_bit;
    IntVar e_capture_frames;
    IntVar e_water_ocean_tesselation;
    IntVar e_shadow_maps_size_ratio;
    IntVar e_shadow_spots;
    IntVar e_use_global_fog_in_fog_volumes;
    IntVar e_precache_level;
    IntVar e_shadow_maps_max_casters_per_object;
    IntVar e_water_ocean_sun_reflection;
    IntVar e_objects_fade_on_distance;
    IntVar e_stencil_shadows_only_from_strongest_light;
    IntVar e_cgf_load_lods;
    IntVar e_optimized_render_object;
    IntVar e_stencil_shadows_build_on_load;
    IntVar e_vegetation_update_shadow_every_frame;
    IntVar e_voxel_build;
    IntVar e_voxel_debug;
    IntVar e_voxel_realtime_light_update;
    IntVar e_widescreen;

    FloatVar e_vegetation_sprites_min_distance;
    FloatVar e_rain_amount;
    FloatVar e_vegetation_sprites_distance_ratio;
    FloatVar e_obj_lod_ratio;
    FloatVar e_obj_view_dist_ratio;
    FloatVar e_dynamic_ambient_ratio;
    FloatVar e_detail_texture_min_fov;
    FloatVar e_terrain_occlusion_culling_precision;
    FloatVar e_vegetation_min_size;
    FloatVar e_terrain_lod_ratio;
    FloatVar e_particles_lod;
    FloatVar e_debug_lights;
    FloatVar e_shadow_maps_view_dist_ratio;
    FloatVar e_decals_life_time_scale;
    FloatVar e_decals_neighbor_max_life_time;
    FloatVar e_obj_min_view_dist;
    FloatVar e_explosion_scale;

    ICVar *e_capture_folder, *e_capture_file_format, *e_deformable_terrain;
};

#endif // _3DENGINE_CVARS_H_
