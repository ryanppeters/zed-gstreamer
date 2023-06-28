// /////////////////////////////////////////////////////////////////////////

//
// Copyright (c) 2020, STEREOLABS.
//
// All rights reserved.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
// A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
// OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
// SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
// LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
// DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// /////////////////////////////////////////////////////////////////////////

#ifndef _GST_ZED_SRC_H_
#define _GST_ZED_SRC_H_

#include <gst/base/gstpushsrc.h>

#include "sl/Camera.hpp"

G_BEGIN_DECLS

#define GST_TYPE_ZED_SRC          (gst_zedsrc_get_type())
#define GST_ZED_SRC(obj)          (G_TYPE_CHECK_INSTANCE_CAST((obj), GST_TYPE_ZED_SRC, GstZedSrc))
#define GST_ZED_SRC_CLASS(klass)  (G_TYPE_CHECK_CLASS_CAST((klass), GST_TYPE_ZED_SRC, GstZedSrcClass))
#define GST_IS_ZED_SRC(obj)       (G_TYPE_CHECK_INSTANCE_TYPE((obj), GST_TYPE_ZED_SRC))
#define GST_IS_ZED_SRC_CLASS(obj) (G_TYPE_CHECK_CLASS_TYPE((klass), GST_TYPE_ZED_SRC))

typedef struct _GstZedSrc GstZedSrc;
typedef struct _GstZedSrcClass GstZedSrcClass;

struct _GstZedSrc {
    GstPushSrc base_zedsrc;

    // ZED camera object
    sl::Camera zed;

    gboolean is_started;   // grab started flag

    // ----> Properties
    gint camera_resolution;   // Camera resolution [enum]
    gint camera_fps;          // Camera FPS
    gboolean sdk_verbose;
    gint camera_image_flip;
    gint camera_id;
    gint64 camera_sn;
    GString svo_file;
    GString stream_ip;
    gint stream_port;
    gint stream_type;
    gfloat depth_min_dist;
    gfloat depth_max_dist;
    gint depth_mode;   // Depth mode [enum]
    gboolean camera_disable_self_calib;
    gboolean depth_stabilization;
    gint coord_sys;
    gboolean roi;
    gint roi_x;
    gint roi_y;
    gint roi_w;
    gint roi_h;
    // gboolean enable_right_side_measure;

    gint confidence_threshold;
    gint texture_confidence_threshold;
    gint measure3D_reference_frame;
    gboolean fill_mode;

    gboolean pos_tracking;
    gboolean camera_static;
    GString area_file_path;
    gboolean enable_area_memory;
    gboolean enable_imu_fusion;
    gboolean enable_pose_smoothing;
    gboolean set_floor_as_origin;
    gboolean set_gravity_as_origin;
    gfloat depth_min_range;
    gfloat init_pose_x;
    gfloat init_pose_y;
    gfloat init_pose_z;
    gfloat init_orient_roll;
    gfloat init_orient_pitch;
    gfloat init_orient_yaw;

    gboolean object_detection;
    gboolean od_image_sync;                          // bool image_sync
    gboolean od_enable_tracking;                     // bool enable_tracking
    gboolean od_enable_segm_output;                  // bool enable_segmentation TODO
    gint od_detection_model;                         // sl::OBJECT_DETECTION_MODEL detection_model
    gfloat od_max_range;                             // float max_range
    gint od_filter_mode;                             // TODO(Walter) sl::OBJECT_FILTERING_MODE filtering_mode
    gfloat od_prediction_timeout_s;                  // float prediction_timeout_s
    gboolean od_allow_reduced_precision_inference;   // bool allow_reduced_precision_inference
    gfloat od_det_conf;                              // TODO(Walter) [runtime] float detection_confidence_threshold
    gboolean od_person;                              // TODO(Walter) [runtime] std::vector< OBJECT_CLASS > object_class_filter
    gboolean od_vehicle;                             // TODO(Walter) [runtime] std::vector< OBJECT_CLASS > object_class_filter
    gboolean od_bag;                                 // TODO(Walter) [runtime] std::vector< OBJECT_CLASS > object_class_filter
    gboolean od_animal;                              // TODO(Walter) [runtime] std::vector< OBJECT_CLASS > object_class_filter
    gboolean od_electronics;                         // TODO(Walter) [runtime] std::vector< OBJECT_CLASS > object_class_filter
    gboolean od_fruit_vegetable;                     // TODO(Walter) [runtime] std::vector< OBJECT_CLASS > object_class_filter
    gboolean od_sport;                               // TODO(Walter) [runtime] std::vector< OBJECT_CLASS > object_class_filter
    gboolean od_person_conf;                         // TODO(Walter) [runtime] std::map< OBJECT_CLASS, float > object_class_detection_confidence_threshold
    gboolean od_vehicle_conf;                        // TODO(Walter) [runtime] std::map< OBJECT_CLASS, float > object_class_detection_confidence_threshold
    gboolean od_bag_conf;                            // TODO(Walter) [runtime] std::map< OBJECT_CLASS, float > object_class_detection_confidence_threshold
    gboolean od_animal_conf;                         // TODO(Walter) [runtime] std::map< OBJECT_CLASS, float > object_class_detection_confidence_threshold
    gboolean od_electronics_conf;                    // TODO(Walter) [runtime] std::map< OBJECT_CLASS, float > object_class_detection_confidence_threshold
    gboolean od_fruit_vegetable_conf;                // TODO(Walter) [runtime] std::map< OBJECT_CLASS, float > object_class_detection_confidence_threshold
    gboolean od_sport_conf;                          // TODO(Walter) [runtime] std::map< OBJECT_CLASS, float > object_class_detection_confidence_threshold

    gboolean body_tracking;           // TODO(Walter)
    gboolean bt_enable_segm_output;   // TODO(Walter) bool enable_segmentation
    gboolean bt_image_sync;           // TODO(Walter) bool image_sync
    gint bt_model;                    // TODO(Walter) sl::BODY_TRACKING_MODEL detection_model
    gint bt_format;                   // TODO(Walter) sl::BODY_FORMAT body_format
    gboolean bt_reduce_precision;     // TODO(Walter) bool allow_reduced_precision_inference
    gfloat bt_max_range;              // TODO(Walter) float max_range
    gint bt_kp_sel;                   // TODO(Walter) sl::BODY_KEYPOINTS_SELECTION body_selection
    gboolean bt_fitting;              // TODO(Walter) bool enable_body_fitting
    gboolean bt_enable_trk;           // TODO(Walter) bool enable_tracking
    gfloat bt_pred_timeout;           // TODO(Walter) float prediction_timeout_s
    gfloat bt_rt_det_conf;            // TODO(Walter) [runtime] float detection_confidence_threshold
    gint bt_rt_min_kp_thresh;         // TODO(Walter) [runtime] int minimum_keypoints_threshold
    gfloat bt_rt_skel_smoothing;      // TODO(Walter) [runtime] float skeleton_smoothing

    gint brightness;
    gint contrast;
    gint hue;
    gint saturation;
    gint sharpness;
    gint gamma;
    gint gain;
    gint exposure;
    gboolean aec_agc;
    gint aec_agc_roi_x;
    gint aec_agc_roi_y;
    gint aec_agc_roi_w;
    gint aec_agc_roi_h;
    gint aec_agc_roi_side;
    gint whitebalance_temperature;
    gboolean whitebalance_temperature_auto;
    gboolean led_status;
    // <---- Properties

    GstClockTime acq_start_time;
    guint32 last_frame_count;
    guint32 total_dropped_frames;

    GstCaps *caps;
    guint out_framesize;

    gboolean stop_requested;
};

struct _GstZedSrcClass {
    GstPushSrcClass base_zedsrc_class;
};

G_GNUC_INTERNAL GType gst_zedsrc_get_type(void);

G_END_DECLS

#endif
